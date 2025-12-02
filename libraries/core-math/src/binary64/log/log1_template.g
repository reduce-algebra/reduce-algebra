@rnd = float<ieee_64,RND>;

p1 = -0x1.ffffffffffffap-2;
p2 = 0x1.555555554f4d8p-2;
p3 = -0x1.0000000537df6p-2;
p4 = 0x1.999a14758b084p-3;
p5 = -0x1.55362255e0f63p-3;
log2_h = 0x1.62e42fefa38p-1;
log2_l = 0x1.ef35793c7673p-45;

r = TEMPR;
l1 = TEMPL1;
l2 = TEMPL2;

z = r * y - 1;
z2 rnd= z * z;
p45 rnd= fma(p5, z, p4);
p23 rnd= fma(p3, z, p2);
ph_1 rnd= fma(p45, z2, p23);
ph_2 rnd= fma(ph_1, z, p1);
ph_3 rnd = ph_2 * z2;

hl = (e * log2_h + l1) + z;
h = rnd(hl);
l_2 rnd= ph_3 + (l_1 + l2);
l_3 rnd= fma(e, log2_l, l_2);

Mz2 = z * z;
M2logp = (((p5 * z + p4) * Mz2 + (p3 * z + p2)) * z + p1) * Mz2;

{
  y in [Y0,Y1] /\ @FLT(y,53) ->
  @FIX(e,0) /\ e in [-0x432,0x400] ->
  |M2logp - M2log| <= 6.98575e-22 ->
  |h + l_1 - hl| <= 3.82621e-29 ->
  |log2_h + log2_l - log2| <= 1.95853e-31 ->
  |l1 + l2 - mlogr| <= 1b-96 ->

  rnd(z) = z /\
  z in ? /\
  ph_3 in ? /\
  l_1 in ? /\
  rnd(e * log2_h + l1) = e * log2_h + l1 /\
  ph_3 - M2logp in ? /\
  l_2 - (ph_3 + (l_1 + l2)) in ? /\
  l_3 - (e * log2_l + l_2) in ? /\
  h + l_3 - (M2log + z + e * log2 + mlogr) in ?
}

l_1 -> h + l_1 - hl - (h - hl);
(h + l_3) - (M2log + z + e * log2 + mlogr) ->
  (l_3 - (e * log2_l + (M2log + (l_1 + l2))) + (h + l_1 - hl)) +
  e * (log2_h + log2_l - log2) +
  (l1 + l2 - mlogr);
