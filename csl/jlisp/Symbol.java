//
// This file is part of the Jlisp implementation of Standard Lisp
// Copyright \u00a9 (C) Codemist Ltd, 1998-2000.
//

// Class to represent Lisp symbols

import java.io.*;

public class Symbol extends LispObject
{

    static int symbolCount = 0;

// ALL LispObjects have car and cdr fields, which can contain other
// LispObjects. So I might as well use those for the fields I would otherwise
// need here that are of that type, ie value and plist. Ugh!

//  LispObject value;        // shallow-binding         use .car instead!
//  LispObject plist;        // property list           use .cdr instead!

    String pname;            // print name
    int cacheFlags;          // used with cacheString to speed up..
    String cacheString;      // .. printing when escape chare may be needed
    public LispFunction fn;         // function (if any)
    SpecialFunction special; // special fn (if any)

// intern() looks up a Java String and find the Lisp
// symbol with that name. It creates it if needbe. This version
// always sets the (pre-defined) function call of this symbol. It is
// only used from cold-start code.

    static Symbol intern(String name, 
                         LispFunction fn, 
                         SpecialFunction special)
    {
        Symbol p;
        int inc = name.hashCode();
        int hash = ((169*inc) & 0x7fffffff) % Jlisp.oblistSize;
        inc = 1 + (inc & 0x7fffffff) % (Jlisp.oblistSize-1);
        for (;;)
        {   p = Jlisp.oblist[hash];
            if (p == null) break;    // symbol is not in oblist
            if (p.pname.equals(name)) 
            {   if (fn != null) p.fn = fn;
                if (special != null) p.special = special;
                return p;
            }
            hash += inc;
            if (hash >= Jlisp.oblistSize) hash -= Jlisp.oblistSize;
        }
// not found on object-list, so create it.
        p = new Symbol();
        p.pname = name;
        p.cacheFlags = -1;
        p.car/*value*/ = Jlisp.lit[Lit.undefined];
        p.cdr/*plist*/ = Jlisp.nil;
        Jlisp.oblist[hash] = p;
        if (fn != null) p.fn = fn;
        else p.fn = new Undefined(name);
        p.special = special;
        Jlisp.oblistCount++;
        if (4*Jlisp.oblistCount > 3*Jlisp.oblistSize) Jlisp.reHashOblist();
        return p;
    }

// now the version of intern() for normal use
    static Symbol intern(String name)
    {
        Symbol p;
        int inc = name.hashCode();
        int hash = ((169*inc) & 0x7fffffff) % Jlisp.oblistSize;
        inc = 1 + (inc & 0x7fffffff) % (Jlisp.oblistSize-1);
        for (;;)
        {   p = Jlisp.oblist[hash];
            if (p == null) break;    // symbol is not in oblist
            if (p.pname.equals(name)) return p;
            hash += inc;
            if (hash >= Jlisp.oblistSize) hash -= Jlisp.oblistSize;
        }
// not found on object-list, so create it.
        p = new Symbol();
        p.pname = name;
        p.cacheFlags = -1;
        p.car/*value*/ = Jlisp.lit[Lit.undefined];
        p.cdr/*plist*/ = Jlisp.nil;
        Jlisp.oblist[hash] = p;
        p.fn = new Undefined(name);
        p.special = null;
        Jlisp.oblistCount++;
        if (4*Jlisp.oblistCount > 3*Jlisp.oblistSize) Jlisp.reHashOblist();
        return p;
    }

    LispObject eval()
    {   return car/*value*/;
    }

    static StringBuffer cache = new StringBuffer();

    String toPrint()
    {
        if ((currentFlags & (printEscape | printLower | printUpper)) == 0)
            return pname;
        else if (currentFlags == cacheFlags) return cacheString;
        cache.setLength(0);
        String p = pname;
        if (p.length() == 0) return p;
        cacheFlags = currentFlags;
        if ((currentFlags & printLower) != 0) p = p.toLowerCase();
        else if ((currentFlags & printUpper) != 0) p = p.toUpperCase();
        char c = p.charAt(0);
        if ((currentFlags & printEscape) != 0)
        {   if (Character.isLetter(c) || c == '_')
            {   if (((Symbol)Jlisp.lit[Lit.lower]).car/*value*/ !=
                    Jlisp.nil)
                {   if (Character.isUpperCase(c))
                        cache.append((char)'!');
                }
                else if (((Symbol)Jlisp.lit[Lit.raise]).car/*value*/ !=
                    Jlisp.nil)
                {   if (Character.isLowerCase(c))
                        cache.append((char)'!');
                }
                cache.append((char)c);
            }
//          else if ((int)c < 32)
//          {   cache.append("\\x" + Integer.toHexString((int)c));
//          }
            else
            {   cache.append((char)'!');
                cache.append((char)c);
            }
        }
        else cache.append((char)c);
        for (int i=1; i<p.length(); i++)
        {   c = p.charAt(i);
            if ((currentFlags & printEscape) != 0)
            {   if (Character.isLetterOrDigit(c) || c == '_')
                {   if (((Symbol)Jlisp.lit[Lit.lower]).car/*value*/ !=
                        Jlisp.nil)
                    {   if (Character.isUpperCase(c))
                            cache.append((char)'!');
                    }
                    else if (((Symbol)Jlisp.lit[Lit.raise]).car/*value*/ !=
                        Jlisp.nil)
                    {   if (Character.isLowerCase(c))
                            cache.append((char)'!');
                    }
                    cache.append((char)c);
                } 
                else if ((int)c < 32)
                {   cache.append("\\x" + Integer.toHexString((int)c));
                }
                else
                {   cache.append((char)'!');
                    cache.append((char)c);
                }
            }
            else cache.append((char)c);
        }
        cacheString = cache.toString();
        return cacheString;
    }
    void iprint()
    {
        String s = toPrint();
        if ((currentFlags & noLineBreak) == 0 &&
            currentOutput.column + s.length() > currentOutput.lineLength)
            currentOutput.println();
        currentOutput.print(s);
    }

    void blankprint()
    {
        String s = toPrint();
        if ((currentFlags & noLineBreak) == 0 &&
            currentOutput.column + s.length() >= currentOutput.lineLength)
            currentOutput.println();
        else currentOutput.print(" ");
        currentOutput.print(s);
    }

    public int lisphashCode()
    { 
        return 139*pname.hashCode() ^ 0x12345678; 
    }

    void scan()
    {
        if (Jlisp.objects.contains(this)) // seen before?
        {   if (!Jlisp.repeatedObjects.containsKey(this))
            {   Jlisp.repeatedObjects.put(
                    this,
                    Jlisp.nil); // value is junk at this stage
            }
        }
        else 
        {   Jlisp.objects.add(this);
            if (Jlisp.descendSymbols)
            {   if (car/*value*/ != null) Jlisp.stack.push(car/*value*/);
                if (cdr/*plist*/ != null) Jlisp.stack.push(cdr/*plist*/);
                if (fn != null) Jlisp.stack.push(fn);
                if (special != null) Jlisp.stack.push(special);
            }
        }
    }
    
    void dump() throws IOException
    {
        Object w = Jlisp.repeatedObjects.get(this);
        if (w != null &&
            w instanceof Integer)
        {   if (Jlisp.specialNil &&
                this == Jlisp.nil) 
                // important enough for a special-case, but must not use
                // that while dumping itself!
                Jlisp.odump.write(X_LIST+0);
            else putSharedRef(w); // processed before
        }
        else
        {   if (w != null) // will be used again sometime
            {   Jlisp.repeatedObjects.put(
                    this,
                    new Integer(Jlisp.sharedIndex++));
                Jlisp.odump.write(X_STORE);
            }
// Now this is the first time I see this symbol while writing a dump
// file. For a symbol I emit
//    SYM n c0 c1 ... cn  // the name
//    special fn plist value
            if (!Jlisp.descendSymbols) // ie for FASL not PRESERVE
            {
// The search here is a crude linear search through the most recent
// 512 symbols mentioned. I could use a hash table but the code overhead
// makes this really simple look attractive as a start.
                 for (int i=0; i<512; i++)
                 {   if (Fasl.recent[i] == this)
                     {    int op = X_RECENT;
                          if (i >= 256)
                          {   op = X_RECENT1;
                              i -= 256;
                          }
                          Jlisp.odump.write(op);
                          Jlisp.odump.write(i);
                          Fasl.recentn++;
                          return;
                     }
                 }
            }
            byte [] rep = pname.getBytes("UTF8");
            int length = rep.length;
// Because I expect it to be a common case I have a special opcode
// for a function that does not have a function associated with it.
// I also have to take special care with uninterned symbols, and since
// I do not have unlimited space in the opcode map I do not manage to
// optimise these two cases at the same time.
            boolean undefined = false;
// NB gensyms are handled as a derived class so do not need attention here
            if (fn instanceof Undefined &&
                Jlisp.repeatedObjects.get(fn) == null)
            {   putPrefix2(length, X_UNDEFn, X_UNDEF);
                undefined = true;
            }
            else putPrefix2(length, X_SYMn, X_SYM);
            for (int i=0; i<length; i++)
                Jlisp.odump.write(rep[i]);
            if (Jlisp.descendSymbols)        
            {   Jlisp.stack.push(car/*value*/);
                Jlisp.stack.push(cdr/*plist*/);
                Jlisp.stack.push(special);
// If the symbol had a non-trivial function-definition then that will
// be dumped straight after the symbol-header/pname info. Otherwise I
// skip and start with the "special-function" info which will usually be
// empty.
                if (!undefined) Jlisp.stack.push(fn);
            }
            else Fasl.recent[Fasl.recentp++ & 0x1ff] = this;
        }
    }
        
}

// End of Symbol.java

