(* charmetrics1.sml *)

(* This decodes stuff from the "charmetrics.sml" hash tables to give
 * information about characters in the STIX (and cmuntt and odokai)
 * fonts. This is a component of ACN adjustments to the code here so that
 * use is made of Unicode fonts not the original TeX ones...
 *)

(* To perform boolean operations on 32-bit integers I need to turn things
   into LargeWord items. This looks clumsy and maybe something simpler
   would be OK (eg maybe I do not need to go via LargeInt) but of this
   works I will feel OK. At least this seems to work on Poly/ML - but
   in general SML may not provide very good guarantees about the width
   of integers that it supports.
 *)

fun andb(a, b) =
   Int.fromLarge (
      LargeWord.toLargeInt (
         LargeWord.andb (
            LargeWord.fromLargeInt (
               LargeInt.toLarge a),
            LargeWord.fromLargeInt (
               LargeInt.toLarge b))));

fun orb(a, b) =
   Int.fromLarge (
      LargeWord.toLargeInt (
         LargeWord.orb (
            LargeWord.fromLargeInt (
               LargeInt.toLarge a),
            LargeWord.fromLargeInt (
               LargeInt.toLarge b))));

fun notb a =
   Int.fromLarge (
      LargeWord.toLargeInt (
         LargeWord.notb (
            LargeWord.fromLargeInt (
               LargeInt.toLarge a))));

fun <<(a, n) =
   Int.fromLarge (
      LargeWord.toLargeInt (
         LargeWord.<< (
            LargeWord.fromLargeInt (
               LargeInt.toLarge a),
               Word.fromInt n)));

fun >>(a, n) =
   Int.fromLarge (
      LargeWord.toLargeInt (
         LargeWord.>> (
            LargeWord.fromLargeInt (
               LargeInt.toLarge a),
               Word.fromInt n)));

fun getv v n = Vector.sub(v, n);

(* The hash table access code here has to be keyed to cod ein a file
 * called "charmetrics.cpp" in the CSL part of the Reduce source code.
 * The stuff there accesses raw font metric information (which is in turn
 * extracted from the .otf font files via a collection of messy steps) and
 * picks hash parameters that let me end up with especially compact
 * metric tables. Well even in the form used here the tables consume
 * quite a lot of space, but I believe they represent a good balance
 * between spaec saving and compact representation given that the Unicode
 * fonts concerned have many thousands of characters (specifically I have
 * over 30,000 codepoints with measurements).
 *)

fun lookupchar fontnum codepoint =
  let
    val cp1 =
(* I first map the font code and (21-bit) codepoint so that codepoints use
   only 16 bits, with certain invalid or unused ranges mapped onto the
   value 0xffff (which does not represent a valid character). The messy
   set of tests here are mostly present because in a hash table I need to
   store keys (as well as values) and if I did not compress the keys
   somewhat I would be very tight on bits when fitting my table into
   a collection of 32-bit words.
 *)
      if fontnum < 2 then
        if andb(codepoint, 0xd800) = 0xd800 then 0xffff
        else if codepoint >= 0x10000 then
          if codepoint < 0x10800 then 0xd800 + andb(codepoint, 0xfff)
          else 0xffff
        else codepoint
      else if codepoint >= 0x4000 andalso codepoint < 0x8000 then 0xffff
      else if codepoint >= 0x1d8000 andalso codepoint < 0x1d9000 then
        0x5000 + andb(codepoint, 0xfff)
      else if codepoint >= 0x10000 then 0xffff
      else codepoint
(* I combine the (reduced) codempoint with the font number to get a key *)
    val fullkey = <<(fontnum, 16) + cp1
    val key = >>(fullkey, 2)
(* My first hash location is merely the key reduced modulo the hash table
   size. This is clearly rather cheap and simplistic, but turns out to
   be good enough.
 *)
    val h1 = key mod hashsize
    val w = getv metrics_hash h1;
    val v = andb((getv w 0), 0x7ffff)
  in
(* If I find my character at its first choice location can unpick information
   and the sub-function lookupchar1 does that.
 *)
    if v = key then lookupchar1 fullkey w fontnum
    else let
(* A second hash function is an offset version of the key modulo a different
   number. These two numbers were chosen following an exhausive search to
   find values that led to high hash table occupancy.
 *)
      val h2 = (key mod CHAR_METRICS_MODULUS) + CHAR_METRICS_OFFSET;
      val w = getv metrics_hash h2;
      val v = andb((getv w 0), 0x7ffff)
    in
      if v = key then lookupchar1 fullkey w fontnum
      else let
(* A third (and final) hash function is simply the sum of the previous two,
   obviously reduced modulo the table size.
 *)
        val h3 = (h1 + h2) mod hashsize;
        val w = getv metrics_hash h3;
        val v = andb((getv w 0), 0x7ffff)
      in
        if v = key then lookupchar1 fullkey w fontnum
(* If the character was not present I will return NONE *)
        else NONE
      end
    end
  end

and lookupchar1 fullkey row fontnum =
  let
    val v = 2*andb(fullkey, 3)
    val wlo = getv row (v+2)
  in
    if wlo = 0 then NONE
    else
      let
        val whi = getv row (v+3)
        val width = andb(>>(whi, 19), 0x1fff)
        val llx   = andb(>>(whi, 6),  0x1fff) - 3000
        val lly   = andb(>>(wlo, 26), 0x3f) +
                    andb(<<(whi, 6),  0xfc0) - 1000
        val urx   = andb(>>(wlo, 13), 0x1fff) - 500
        val ury   = andb(wlo, 0x1fff) - 1000
        val ki =
          if v = 0      then andb(>>(getv row 0, 19), 0x7ff)
          else if v = 2 then andb(>>(getv row 0, 30), 0x3) +
                             andb(<<(getv row 1, 2), 0x7fc)
          else if v = 4 then andb(>>(getv row 1, 9), 0x7ff)
          else (* v = 6 *)   andb(>>(getv row 1, 20), 0x7ff);
        val kerninfo =
          if ki = 0 then 0
          else ki + (getv fontkern fontnum)
      in 
        SOME (width, llx, lly, urx, ury, kerninfo)
      end
  end;


(* Given the output from lookupchar you can then the following with a
   second codepoint (which must be in the same font) to find an adjustment
   to the space between the two characters so that they are properly
   kerned. The initial metric information provides an index into the
   main kern table, and the code then does a linear search starting from
   there to seek information relevant to the succesor character. This
   is sort of reasonable because any one character only has a modest
   number of successor thet kern with it. The table in fact contains both
   kern and ligature information, and a bit flags a particular entry to
   note which sort of adjustment is being recorded in any given word.
 *)

fun lookupkernadjustment NONE cp = 0
  | lookupkernadjustment (SOME (width, llx, lly, urx, ury, kerninfo)) cp =
  if kerninfo = 0 then 0
  else let
    fun seek i =
      let
        val w = getv kerntable i
      in
        if andb(w, 0x001fffff) = cp andalso
           andb(w, 0x00200000) = 0 then
          let
            val w1 = andb(>>(w, 23), 0x1ff)
          in
            if andb(w1, 0x100) = 0 then w1
            else w1 - 0x200
          end
        else if andb(w, 0x00400000) <> 0 then 0
        else seek (i + 1)
      end
   in
     seek kerninfo
   end;

(* For instance if you have just looked up "f" and you now go
   (lookupligature ... "i") you should get back SOME ("fi") where the
   result is the numeric codepoint for an f-i-ligature. If no ligature
   is available you get back NONE.
 *)

fun lookupligature NONE cp = NONE
  | lookupligature (SOME (width, llx, lly, urx, ury, kerninfo)) cp =
  if kerninfo = 0 then NONE
  else let
    fun seek i =
      let
        val w = getv kerntable i
      in
        if andb(w, 0x001fffff) = cp andalso
           andb(w, 0x00200000) <> 0 then SOME(andb(>>(w, 23), 0x1ff))
        else if andb(w, 0x00400000) <> 0 then NONE
        else seek (i + 1)
      end
   in
     seek kerninfo
   end;

(* On Original TeX accent positions above characters were adjusted using
   information that was stored in the kern table. Here I have a separate
   table for accent offsets, arranged as a hash table that uses at worst
   two probes. This returns 0 if there us no adjustment needed (or
   know adjustment know about). Note that the values in the table
   are treated as 32-bit signed numbers. This information is only
   present in the STIXMath font (of the fonts I am using) and so I do
   not worry about other fonts here!
 *)

fun extend11 n =
  if andb(n, 0x400) = 0 then n
  else n - 0x800;

fun accentposition key =
  let
    val h1 = key mod TOPCENTRE_SIZE
    val w = getv topcentre_hash h1
    val v = andb(w, 0x1fffff)
    in
      if v = key then extend11(>>(w, 21))
      else
        let
          val h2 = key mod TOPCENTRE_MODULUS + TOPCENTRE_OFFSET
          val w = getv topcentre_hash h2
          val v = andb(w, 0x1fffffff)
        in
          if v = key then extend11(>>(w, 21))
          else 0
        end
    end;

(* The the STIXMath font there are tables for "variants" and for
   "extended characters". The first copes with single glyphs that
   render as a range of sized of (sor instance) parentheses. The
   latter gives information about a set of characters that can be used
   to build up seriously over-sized delimiters as in
      /   top hook
      |   top extension
     <    middle part
      |   lower extension
      \   lower hook
   At present I do not really understand the intent of all the
   data present and associated with the parts! As with accent
   positions the data I have here only applies in the STIXMath font.
   (variants cp) returns a Vector of length 6 where each element
   is either a codepoint or zero (or NONE if no variants are
   available at all).
*)

fun variants key =
  let
    val h1 = key mod VARIANT_SIZE
    val w = getv variant_hash h1
    val v = getv w 0
    in
      if v = key then SOME w
      else
        let
          val h2 = key mod VARIANT_MODULUS + VARIANT_OFFSET
          val w = getv variant_hash h2
          val v = getv w 0
          in
            if v = key then SOME w
            else
              let
                val h3 = (h1 + h2) mod VARIANT_SIZE
                val w = getv variant_hash h1
                val v = getv w 0
              in
                if v = key then SOME w
                else NONE
              end
        end
  end;

(* Same sort of idea but for extensions and you get back a longer vector *)

fun extension key =
  let
    val h1 = key mod EXTENSION_SIZE
    val w = getv extension_hash h1
    val v = getv w 0
    in
      if v = key then SOME w
      else
        let
          val h2 = key mod EXTENSION_MODULUS + EXTENSION_OFFSET
          val w = getv extension_hash h2
          val v = getv w 0
          in
            if v = key then SOME w
            else
              let
                val h3 = (h1 + h2) mod EXTENSION_SIZE
                val w = getv extension_hash h1
                val v = getv w 0
              in
                if v = key then SOME w
                else NONE
              end
        end
  end;


(* end of Metrics.sml *)


