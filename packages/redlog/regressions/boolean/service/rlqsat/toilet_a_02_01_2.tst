off rlabout;

rlset ibalp;

% The formula toilet_a_02_01.2.qdimacs of Castellini's encoding of the
% bomb in the toilet problem http://www.qbflib.org
toilet_a_02_01_2 :=
ex(var4,ex(var5,ex(var6,ex(var7,ex(var8,ex(var9,all(var12,all(var13,ex(var1,ex(
var2,ex(var3,ex(var10,ex(var11,ex(var14,ex(var15,ex(var16,ex(var17,ex(var18,(not
(var13 = 1) or var12 = 1 or var14 = 1) and (not(var13 = 1) or not(var15 = 1) or
var12 = 1) and (not(var14 = 1) or var12 = 1 or var13 = 1) and (var12 = 1 or
var13 = 1 or var15 = 1) and (not(var12 = 1) or var13 = 1 or var14 = 1) and (not(
var12 = 1) or var13 = 1 or var15 = 1) and not(var16 = 1) and not(var17 = 1) and
not(var18 = 1) and (not(var4 = 1) or not(var18 = 1)) and (not(var4 = 1) or not(
var16 = 1)) and (not(var6 = 1) or not(var17 = 1)) and (not(var6 = 1) or not(
var18 = 1)) and (not(var7 = 1) or var18 = 1) and (not(var4 = 1) or var2 = 1) and
 (not(var4 = 1) or not(var10 = 1)) and (not(var4 = 1) or var1 = 1) and (not(var6
 = 1) or var3 = 1) and (not(var6 = 1) or not(var11 = 1)) and (not(var6 = 1) or
var2 = 1) and (not(var2 = 1) or not(var7 = 1)) and (not(var1 = 1) or var4 = 1 or
 var16 = 1) and (not(var16 = 1) or var1 = 1) and (not(var2 = 1) or var4 = 1 or
var6 = 1 or var18 = 1) and (not(var18 = 1) or var2 = 1 or var7 = 1) and (not(
var10 = 1) or var15 = 1) and (not(var15 = 1) or var4 = 1 or var10 = 1) and (not(
var3 = 1) or var6 = 1 or var17 = 1) and (not(var17 = 1) or var3 = 1) and (not(
var11 = 1) or var14 = 1) and (not(var14 = 1) or var6 = 1 or var11 = 1) and (not(
var4 = 1) or not(var6 = 1)) and (not(var5 = 1) or not(var8 = 1)) and (not(var4 =
 1) or not(var7 = 1)) and (not(var5 = 1) or not(var9 = 1)) and (not(var6 = 1) or
 not(var7 = 1)) and (not(var8 = 1) or not(var9 = 1)) and not(var10 = 1) and not(
var11 = 1)))))))))))))))))))$

rlqsat toilet_a_02_01_2;

end;
