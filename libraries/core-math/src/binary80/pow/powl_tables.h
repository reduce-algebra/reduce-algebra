#pragma once

typedef struct {
	double r;
	double mlogrh, mlogrl;
	long int z;
} lut_t;

typedef struct {
	int64_t h;
	union {
		unsigned __int128 l;
		struct {uint64_t ll; uint64_t lh;}; // little endian
	};
} corr_t;

/* For 0 <= i < 128, r1[i] is a 9-bit approximation of 1/x for
   l[i] <= x < h[i], with l[i] = 1 + i/2^7 and
   h[i] = 1 + (i+1)/2^7 and
   z[i]+mlogrh[i] + mlogrl[i] is a double-double approximation of -log2(r1[i]),
   with relative error < 2^-107.22.
   Also we have |r1[i]*x - 1| <= 2^-7 for l[i] <= x < h[i].
   This table is build with routine get_coarsetbl(m=9,L=7)
   from file powl.sage.
*/
static const _Alignas(16)
lut_t coarse[128] = {
{0x1p+0, 0x0p+0, 0x0p+0,0},//0x1p-7
{0x1.fap-1, 0x1.16a21e20a0a45p-6, 0x1.79268271cbde1p-63,0},//0x1.06p-8
{0x1.f6p-1, 0x1.d23afc49139f9p-6, -0x1.90c94610afb5fp-60,0},//0x1.14p-8
{0x1.f2p-1, 0x1.47aa07357704fp-5, 0x1.5a51cc6227b89p-60,0},//0x1.2ap-8
{0x1.efp-1, 0x1.8f135b8107912p-5, -0x1.8afdf33294c96p-59,0},//0x1.2bp-8
{0x1.ebp-1, 0x1.eef792508b69dp-5, 0x1.84dcc96e6c77ap-59,0},//0x1.02p-8
{0x1.e7p-1, 0x1.27d24bae824dbp-4, -0x1.effaf024a8bedp-59,0},//0x1.16p-8
{0x1.e4p-1, 0x1.4c560fe68af88p-4, 0x1.c141e66faaaadp-61,0},//0x1.2p-8
{0x1.ep-1, 0x1.7d60496cfbb4cp-4, 0x1.9ced1447e30adp-58,0},//0x1p-8
{0x1.ddp-1, 0x1.a26ccd9981853p-4, -0x1.d9af608a7a4d8p-58,0},//0x1.22p-8
{0x1.d9p-1, 0x1.d4300a2524d41p-4, 0x1.dacd2ed722083p-58,0},//0x1.06p-8
{0x1.d6p-1, 0x1.f9c95dc1d1165p-4, -0x1.6cd4d2ae3a2f6p-60,0},//0x1.08p-8
{0x1.d2p-1, 0x1.162593186da7p-3, -0x1.df0fdbc295d19p-58,0},//0x1.28p-8
{0x1.cfp-1, 0x1.293ac3dc1a668p-3, 0x1.979619fe2f08ap-57,0},//0x1.fap-9
{0x1.ccp-1, 0x1.3c6fb650cde51p-3, -0x1.7a6ed4e1b0936p-57,0},//0x1.e8p-9
{0x1.c9p-1, 0x1.4fc4d4d9bb313p-3, 0x1.7c2c3172b86afp-57,0},//0x1.1p-8
{0x1.c6p-1, 0x1.633a8bf437ce1p-3, 0x1.54fae008fbb59p-60,0},//0x1.26p-8
{0x1.c2p-1, 0x1.7d60496cfbb4cp-3, 0x1.9ced1447e30adp-57,0},//0x1.1ep-8
{0x1.bfp-1, 0x1.9123c1528c6cep-3, -0x1.0b273219ed335p-59,0},//0x1.12p-8
{0x1.bcp-1, 0x1.a5094b54d2828p-3, 0x1.013b6eaceb921p-57,0},//0x1.0cp-8
{0x1.b9p-1, 0x1.b9115db83a3ddp-3, 0x1.69a95f528f2c7p-58,0},//0x1.0cp-8
{0x1.b6p-1, 0x1.cd3c712d31109p-3, 0x1.92eeaf409cc88p-58,0},//0x1.12p-8
{0x1.b3p-1, 0x1.e18b00e13123dp-3, 0x1.9bf75f08df8fbp-61,0},//0x1.1ep-8
{0x1.b1p-1, 0x1.ef28aacd72231p-3, 0x1.06313e79cf1dcp-58,0},//0x1.18p-8
{0x1.aep-1, 0x1.01d9bbcfa61d4p-2, 0x1.768994400ca0ap-56,0},//0x1.fcp-9
{0x1.abp-1, 0x1.0c318aedff3cp-2, 0x1.d99b6125b9d35p-56,0},//0x1.bcp-9
{0x1.a8p-1, 0x1.169c05363f158p-2, 0x1.c8d43e017579bp-56,0},//0x1.ep-9
{0x1.a5p-1, 0x1.21196e87473d1p-2, -0x1.343f87991ca1fp-56,0},//0x1.19p-8
{0x1.a3p-1, 0x1.28225bb5e64a4p-2, -0x1.7154f4085d044p-58,0},//0x1.eep-9
{0x1.ap-1, 0x1.32bfee370ee68p-2, 0x1.968925e378d68p-56,0},//0x1.cp-9
{0x1.9dp-1, 0x1.3d712bf9c9defp-2, -0x1.9cee46ebe3a2dp-57,0},//0x1.1ap-8
{0x1.9bp-1, 0x1.449d115ef7d87p-2, 0x1.b1edc2a4a845dp-56,0},//0x1.cp-9
{0x1.98p-1, 0x1.4f6fbb2cec598p-2, 0x1.e393a16b94b52p-56,0},//0x1p-8
{0x1.96p-1, 0x1.56b22e6b578e5p-2, -0x1.8d86531d55da2p-56,0},//0x1.d8p-9
{0x1.93p-1, 0x1.61a717cac1983p-2, 0x1.15f01e8fdf6adp-58,0},//0x1.f4p-9
{0x1.91p-1, 0x1.6900a8836d0d5p-2, 0x1.d3cd794eee08bp-60,0},//0x1.c8p-9
{0x1.8ep-1, 0x1.7418acebbf18fp-2, -0x1.26bfff0133975p-56,0},//0x1.08p-8
{0x1.8cp-1, 0x1.7b89f02cf2aadp-2, 0x1.8f89e2eb553b2p-57,0},//0x1.9p-9
{0x1.8ap-1, 0x1.8304d90c11fd3p-2, 0x1.51d58525aad39p-57,0},//0x1.06p-8
{0x1.87p-1, 0x1.8e4f83fa145eep-2, -0x1.40df0e173c574p-56,0},//0x1.dep-9
{0x1.85p-1, 0x1.95e2f9b51f04ep-2, 0x1.793366c239cadp-57,0},//0x1.9ap-9
{0x1.83p-1, 0x1.9d806ebc9921cp-2, -0x1.cf91d2080a35bp-56,0},//0x1.fcp-9
{0x1.8p-1, 0x1.a8ff971810a5ep-2, 0x1.817fd3b7d7e5dp-58,0},//0x1p-8
{0x1.7ep-1, 0x1.b0b67f4f4681p-2, -0x1.5e13b838eba7dp-59,0},//0x1.acp-9
{0x1.7cp-1, 0x1.b877c57b1b07p-2, -0x1.01d98c3531027p-58,0},//0x1.98p-9
{0x1.7ap-1, 0x1.c043859e2fdb3p-2, 0x1.edf515c63dd87p-56,0},//0x1.d8p-9
{0x1.78p-1, 0x1.c819dc2d45fe4p-2, 0x1.c4aec56233279p-57,0},//0x1.08p-8
{0x1.75p-1, 0x1.d3ef776d43ff4p-2, -0x1.e2b378ff59cbbp-59,0},//0x1.05p-8
{0x1.73p-1, 0x1.dbe0c58c3cff2p-2, -0x1.6a568b022e9a3p-56,0},//0x1.ep-9
{0x1.71p-1, 0x1.e3dd1156507dep-2, -0x1.3aeabca24fd25p-57,0},//0x1.bep-9
{0x1.6fp-1, 0x1.ebe47960e3c08p-2, 0x1.ff93949a1897dp-56,0},//0x1.a4p-9
{0x1.6dp-1, 0x1.f3f71cc1b629cp-2, -0x1.f4c8f8f9cbfe1p-56,0},//0x1.92p-9
{0x1.6bp-1, 0x1.fc151b11b364p-2, 0x1.b9a81085cd3b3p-58,0},//0x1.88p-9
{0x1.69p-1, -0x1.fbc16b902680ap-2, -0x1.1d46ccc53c278p-57,1},//0x1.86p-9
{0x1.67p-1, -0x1.f38c567bcc541p-2, 0x1.780e41697a095p-57,1},//0x1.8cp-9
{0x1.65p-1, -0x1.eb4b847d15bcep-2, -0x1.4f9727980f5edp-56,1},//0x1.9ap-9
{0x1.63p-1, -0x1.e2fed3d097298p-2, -0x1.be44aae7442abp-59,1},//0x1.bp-9
{0x1.61p-1, -0x1.daa6222064fb9p-2, -0x1.274a5715611b7p-62,1},//0x1.cep-9
{0x1.5fp-1, -0x1.d2414c80bf27dp-2, -0x1.4856fb52a53d2p-56,1},//0x1.f4p-9
{0x1.5ep-1, -0x1.ce0a4923a587dp-2, 0x1.b517ae88c2fd3p-57,1},//0x1.08p-8
{0x1.5cp-1, -0x1.c592fad295b56p-2, -0x1.f9fb952bbbcccp-56,1},//0x1.d8p-9
{0x1.5ap-1, -0x1.bd0f2e9e79031p-2, 0x1.52ef4c737fba5p-56,1},//0x1.98p-9
{0x1.58p-1, -0x1.b47ebf73882a1p-2, 0x1.6fae441c09d76p-56,1},//0x1.6p-9
{0x1.56p-1, -0x1.abe18797f1f49p-2, 0x1.e5b8daaa73a43p-58,1},//0x1.acp-9
{0x1.54p-1, -0x1.a33760a7f6051p-2, 0x1.8a0efca1a184fp-56,1},//0x1p-8
{0x1.53p-1, -0x1.9edd6759b25ep-2, 0x1.dc938c18e544dp-56,1},//0x1.ccp-9
{0x1.51p-1, -0x1.961f90527409cp-2, 0x1.cc298a148e6cap-56,1},//0x1.66p-9
{0x1.4fp-1, -0x1.8d54673b5c372p-2, 0x1.530bdb6949302p-56,1},//0x1.a6p-9
{0x1.4ep-1, -0x1.88e9c72e0b226p-2, 0x1.6d266d6cdc959p-56,1},//0x1.06p-8
{0x1.4cp-1, -0x1.800a563161c54p-2, -0x1.9575b04fa6fbdp-57,1},//0x1.9p-9
{0x1.4ap-1, -0x1.771d2ba7efb3cp-2, 0x1.b90132aeddb58p-58,1},//0x1.88p-9
{0x1.48p-1, -0x1.6e221cd9d0cdep-2, -0x1.5e35482d13dc1p-56,1},//0x1.08p-8
{0x1.47p-1, -0x1.699f5248cd4b8p-2, -0x1.a3152150d2dbfp-56,1},//0x1.7ep-9
{0x1.45p-1, -0x1.608f1b42948aep-2, 0x1.a43fc62b7e69p-56,1},//0x1.a6p-9
{0x1.44p-1, -0x1.5c01a39fbd688p-2, 0x1.817fd3b7d7e5dp-56,1},//0x1.d8p-9
{0x1.42p-1, -0x1.52dbdfc4c96b3p-2, -0x1.f73d83987f26dp-56,1},//0x1.54p-9
{0x1.4p-1, -0x1.49a784bcd1b8bp-2, 0x1.b6d40900b2502p-62,1},//0x1p-8
{0x1.3fp-1, -0x1.4507cfedd4fc4p-2, 0x1.aca97d800ce47p-56,1},//0x1.64p-9
{0x1.3dp-1, -0x1.3bbd3a0a1dcfbp-2, 0x1.a9f3c8bc9672ep-56,1},//0x1.d4p-9
{0x1.3cp-1, -0x1.37124cea4cdedp-2, 0x1.3376649b4fc09p-57,1},//0x1.8p-9
{0x1.3ap-1, -0x1.2db10fc4d9aafp-2, -0x1.bc4de8f631bcfp-56,1},//0x1.cp-9
{0x1.39p-1, -0x1.28fab35b32683p-2, -0x1.8c0e85a908be6p-56,1},//0x1.84p-9
{0x1.37p-1, -0x1.1f825f6d88e13p-2, -0x1.5f43469fbe6eap-57,1},//0x1.c4p-9
{0x1.36p-1, -0x1.1ac05b291f07p-2, -0x1.4a31ce1b7e328p-56,1},//0x1.7p-9
{0x1.34p-1, -0x1.11307dad30b76p-2, 0x1.a7b47d2c352d9p-57,1},//0x1.ep-9
{0x1.33p-1, -0x1.0c62975542a8fp-2, 0x1.6c13816f9f48p-56,1},//0x1.44p-9
{0x1.32p-1, -0x1.0790adbb03009p-2, -0x1.bc0c69a675517p-56,1},//0x1.fcp-9
{0x1.3p-1, -0x1.fbc16b902680ap-3, -0x1.1d46ccc53c278p-58,1},//0x1.6p-9
{0x1.2fp-1, -0x1.f205339208f27p-3, -0x1.1dd4a99cc633bp-57,1},//0x1.aep-9
{0x1.2dp-1, -0x1.de73fe3b1480fp-3, 0x1.e41bd8c32e1bep-59,1},//0x1.b6p-9
{0x1.2cp-1, -0x1.d49ee4c32597p-3, 0x1.b85a54d7ee2fdp-58,1},//0x1.48p-9
{0x1.2bp-1, -0x1.cac163c770dc9p-3, 0x1.a4ecd69d3b872p-57,1},//0x1.e8p-9
{0x1.29p-1, -0x1.b6ecf175f95e9p-3, -0x1.afb63338bed1fp-57,1},//0x1.88p-9
{0x1.28p-1, -0x1.acf5e2db4ec94p-3, 0x1.01ee1343fe7cap-59,1},//0x1.6p-9
{0x1.27p-1, -0x1.a2f632320b86bp-3, 0x1.ae3bd6c6d42fp-58,1},//0x1.f2p-9
{0x1.25p-1, -0x1.8edcae8352b6cp-3, 0x1.28caf799ad993p-57,1},//0x1.8ap-9
{0x1.24p-1, -0x1.84c2bd02f03b3p-3, 0x1.16edb88c4e2b5p-62,1},//0x1.48p-9
{0x1.23p-1, -0x1.7a9fec7d05ddfp-3, 0x1.d0364be23e873p-60,1},//0x1.ccp-9
{0x1.21p-1, -0x1.663f6fac91316p-3, -0x1.f3314e0985116p-57,1},//0x1.bcp-9
{0x1.2p-1, -0x1.5c01a39fbd688p-3, 0x1.817fd3b7d7e5dp-57,1},//0x1.4p-9
{0x1.1fp-1, -0x1.51bab907a5c8ap-3, -0x1.22c022616fdffp-57,1},//0x1.76p-9
{0x1.1ep-1, -0x1.476a9f983f74dp-3, -0x1.89c74a0b21fb6p-58,1},//0x1.e8p-9
{0x1.1cp-1, -0x1.32ae9e278ae1ap-3, -0x1.f51f2c075a74cp-59,1},//0x1.bp-9
{0x1.1bp-1, -0x1.284294b07a64p-3, 0x1.ca25d54d6f775p-57,1},//0x1.46p-9
{0x1.1ap-1, -0x1.1dcd197552b7bp-3, -0x1.7a9150c1e0e58p-57,1},//0x1.54p-9
{0x1.19p-1, -0x1.134e1b489062ep-3, 0x1.94b7dfe0d99a5p-64,1},//0x1.b4p-9
{0x1.17p-1, -0x1.fc66a0f0b00a5p-4, 0x1.becb2e71abdc8p-58,1},//0x1.f4p-9
{0x1.16p-1, -0x1.e72ec117fa5b2p-4, -0x1.cbdb5d9dc29f2p-60,1},//0x1.9cp-9
{0x1.15p-1, -0x1.d1e34e35b82dap-4, -0x1.342ce3cc8f2f9p-58,1},//0x1.48p-9
{0x1.14p-1, -0x1.bc84240adabbap-4, -0x1.8ecb169b9465fp-58,1},//0x1.3p-9
{0x1.13p-1, -0x1.a7111df348494p-4, 0x1.4bba7e1c43d2cp-60,1},//0x1.7ap-9
{0x1.12p-1, -0x1.918a16e46335bp-4, 0x1.463736dac9317p-58,1},//0x1.cp-9
{0x1.1p-1, -0x1.663f6fac91316p-4, -0x1.f3314e0985116p-58,1},//0x1p-8
{0x1.0fp-1, -0x1.507b836033bb7p-4, 0x1.58696424b2e96p-59,1},//0x1.c2p-9
{0x1.0ep-1, -0x1.3aa2fdd27f1c3p-4, 0x1.3fd9776f25acfp-59,1},//0x1.88p-9
{0x1.0dp-1, -0x1.24b5b7e135a3dp-4, 0x1.d974c32ba8269p-58,1},//0x1.52p-9
{0x1.0cp-1, -0x1.0eb389fa29f9bp-4, 0x1.30c22d15199b8p-58,1},//0x1.2p-9
{0x1.0bp-1, -0x1.f1389833253ap-5, 0x1.78cbe51121a94p-59,1},//0x1.24p-9
{0x1.0ap-1, -0x1.c4dfab90aab5fp-5, 0x1.60e0f2c3388fp-62,1},//0x1.4cp-9
{0x1.09p-1, -0x1.985bfc3495194p-5, -0x1.82838ed43de84p-59,1},//0x1.7p-9
{0x1.08p-1, -0x1.6bad3758efd87p-5, -0x1.89b03784b5be1p-60,1},//0x1.9p-9
{0x1.07p-1, -0x1.3ed3094685a26p-5, -0x1.013a5b81fc494p-60,1},//0x1.acp-9
{0x1.06p-1, -0x1.11cd1d5133413p-5, 0x1.27ebafb056cb9p-61,1},//0x1.c4p-9
{0x1.05p-1, -0x1.c9363ba850f86p-6, -0x1.99ba03dc5d34fp-60,1},//0x1.d8p-9
{0x1.04p-1, -0x1.6e79685c2d22ap-6, 0x1.d6476077b9fbdp-60,1},//0x1.e8p-9
{0x1.03p-1, -0x1.1363117a97b0cp-6, -0x1.2ed069b244452p-60,1},//0x1.f4p-9
{0x1.02p-1, -0x1.6fe50b6ef0851p-7, -0x1.fe38dec005e54p-61,1},//0x1.fcp-9
{0x1p-1, 0x0p+0, 0x0p+0,1},//0x1p-8
};

/* For 0 <= i < 128, r2[i] is a 13-bit approximation of 1/x for
   l[i] <= x < h[i], where l[i] = 1 + i*2^-12, h[i] = 1 + (i+1)*2^-12
   for 0 <= i < 32, and l[i] = 1 - 2^-7 + (i-64)*2^-13,
   h[i] = 1 - 2^-7 + (i+1-64)*2^-13 for 64 <= i < 128
   (the entries for 32 <= i < 64 are not used).
   mlogrh[i] + mlogrl[i] is a double-double approximation of -log2(r2[i]),
   with relative error < 2^-107.27.
   Also we have |r2[i]*x - 1| <= 2^-12 for l[i] <= x < h[i].
   This table is build with routine get_finetbl(m=13,L=7)
   from file powl.sage.
   The comment entries at the end of each line are the values of l[i] and h[i],
   and the value of i.
*/
static const _Alignas(16)
lut_t fine[128] = {
{0x1p+0, 0x0p+0, 0x0p+0, 0}, //0x1p+0,0x1.001p+0(0x0)
{0x1.ffdp-1, 0x1.150c5586012b8p-11, 0x1.09d379fa18c5dp-67, 0}, //0x1.001p+0,0x1.002p+0(0x1)
{0x1.ffbp-1, 0x1.cdcda8e93107fp-11, 0x1.f183ca5b21bfep-65, 0}, //0x1.002p+0,0x1.003p+0(0x2)
{0x1.ff9p-1, 0x1.434d4546227fcp-10, 0x1.236028e962f8p-64, 0}, //0x1.003p+0,0x1.004p+0(0x3)
{0x1.ff7p-1, 0x1.9fb97df0b0cc2p-10, -0x1.2f249a6b923ap-64, 0}, //0x1.004p+0,0x1.005p+0(0x4)
{0x1.ff5p-1, 0x1.fc2b7f2d786a5p-10, -0x1.ca7604812d77bp-64, 0}, //0x1.005p+0,0x1.006p+0(0x5)
{0x1.ff3p-1, 0x1.2c51a4dae8915p-9, -0x1.e033bcac726d3p-63, 0}, //0x1.006p+0,0x1.007p+0(0x6)
{0x1.ff1p-1, 0x1.5a906f219ac67p-9, 0x1.fa94c99761b8fp-64, 0}, //0x1.007p+0,0x1.008p+0(0x7)
{0x1.fefp-1, 0x1.88d21ec7a18cdp-9, 0x1.50bf7b995b49ap-63, 0}, //0x1.008p+0,0x1.009p+0(0x8)
{0x1.fedp-1, 0x1.b716b429dd0d3p-9, -0x1.a05d0d4461ea9p-64, 0}, //0x1.009p+0,0x1.00ap+0(0x9)
{0x1.febp-1, 0x1.e55e2fa53ee53p-9, -0x1.1fc262efaad6cp-63, 0}, //0x1.00ap+0,0x1.00bp+0(0xa)
{0x1.fe9p-1, 0x1.09d448cb6515fp-8, -0x1.8c482d244d426p-62, 0}, //0x1.00bp+0,0x1.00cp+0(0xb)
{0x1.fe7p-1, 0x1.20faed2dc9bafp-8, -0x1.8e20466b03b1dp-63, 0}, //0x1.00cp+0,0x1.00dp+0(0xc)
{0x1.fe5p-1, 0x1.38230528606dp-8, 0x1.092c038f19ee9p-62, 0}, //0x1.00dp+0,0x1.00ep+0(0xd)
{0x1.fe3p-1, 0x1.4f4c90e9c4fadp-8, 0x1.b286672a7ab55p-64, 0}, //0x1.00ep+0,0x1.00fp+0(0xe)
{0x1.fe1p-1, 0x1.667790a09bf86p-8, 0x1.e2125cd190b4p-62, 0}, //0x1.00fp+0,0x1.01p+0(0xf)
{0x1.fdfp-1, 0x1.7da4047b92c18p-8, -0x1.3d51cb91dcd91p-62, 0}, //0x1.01p+0,0x1.011p+0(0x10)
{0x1.fddp-1, 0x1.94d1eca95f7bap-8, -0x1.add4dd2830534p-62, 0}, //0x1.011p+0,0x1.012p+0(0x11)
{0x1.fdbp-1, 0x1.ac014958c1186p-8, -0x1.04dbf411afc28p-62, 0}, //0x1.012p+0,0x1.013p+0(0x12)
{0x1.fd9p-1, 0x1.c3321ab87f57ap-8, -0x1.20c3f7a0c05b9p-64, 0}, //0x1.013p+0,0x1.014p+0(0x13)
{0x1.fd7p-1, 0x1.da6460f76ac9bp-8, 0x1.a71bce779c2f7p-62, 0}, //0x1.014p+0,0x1.015p+0(0x14)
{0x1.fd5p-1, 0x1.f1981c445cd1ap-8, 0x1.ce4b718bc4d8cp-62, 0}, //0x1.015p+0,0x1.016p+0(0x15)
{0x1.fd3p-1, 0x1.0466a6671bd3bp-7, -0x1.f1dd3ec6238d1p-63, 0}, //0x1.016p+0,0x1.017p+0(0x16)
{0x1.fd1p-1, 0x1.1001f961f32cfp-7, 0x1.a4f4bcc23842bp-66, 0}, //0x1.017p+0,0x1.018p+0(0x17)
{0x1.fcfp-1, 0x1.1b9e072a2e68dp-7, -0x1.f883c01149a56p-62, 0}, //0x1.018p+0,0x1.019p+0(0x18)
{0x1.fcdp-1, 0x1.273acfd74be94p-7, -0x1.8738012fcfb2cp-62, 0}, //0x1.019p+0,0x1.01ap+0(0x19)
{0x1.fcbp-1, 0x1.32d85380ce7f2p-7, 0x1.3205b7ef063f7p-61, 0}, //0x1.01ap+0,0x1.01bp+0(0x1a)
{0x1.fc9p-1, 0x1.3e76923e3d6b7p-7, -0x1.93b476a7d157cp-61, 0}, //0x1.01bp+0,0x1.01cp+0(0x1b)
{0x1.fc7p-1, 0x1.4a158c2724601p-7, 0x1.f9f06455adecp-62, 0}, //0x1.01cp+0,0x1.01dp+0(0x1c)
{0x1.fc5p-1, 0x1.55b5415313817p-7, -0x1.d870d040a42aap-62, 0}, //0x1.01dp+0,0x1.01ep+0(0x1d)
{0x1.fc3p-1, 0x1.6155b1d99f672p-7, -0x1.572a1b6cd63cfp-61, 0}, //0x1.01ep+0,0x1.01fp+0(0x1e)
{0x1.fc1p-1, 0x1.6cf6ddd2611d4p-7, 0x1.3d979ddf4746cp-61, 0}, //0x1.01fp+0,0x1.02p+0(0x1f)
{0,0,0,0}, // unused
{0,0,0,0}, // unused
{0,0,0,0}, // unused
{0,0,0,0}, // unused
{0,0,0,0}, // unused
{0,0,0,0}, // unused
{0,0,0,0}, // unused
{0,0,0,0}, // unused
{0,0,0,0}, // unused
{0,0,0,0}, // unused
{0,0,0,0}, // unused
{0,0,0,0}, // unused
{0,0,0,0}, // unused
{0,0,0,0}, // unused
{0,0,0,0}, // unused
{0,0,0,0}, // unused
{0,0,0,0}, // unused
{0,0,0,0}, // unused
{0,0,0,0}, // unused
{0,0,0,0}, // unused
{0,0,0,0}, // unused
{0,0,0,0}, // unused
{0,0,0,0}, // unused
{0,0,0,0}, // unused
{0,0,0,0}, // unused
{0,0,0,0}, // unused
{0,0,0,0}, // unused
{0,0,0,0}, // unused
{0,0,0,0}, // unused
{0,0,0,0}, // unused
{0,0,0,0}, // unused
{0,0,0,0}, // unused
{0x1.02p+0, -0x1.6fe50b6ef0851p-7, -0x1.fe38dec005e54p-61, 0}, //0x1.fcp-1,0x1.fc1p-1(0x40)
{0x1.01fp+0, -0x1.6470f448fb051p-7, 0x1.8e540bc781d41p-61, 0}, //0x1.fc1p-1,0x1.fc2p-1(0x41)
{0x1.01fp+0, -0x1.6470f448fb051p-7, 0x1.8e540bc781d41p-61, 0}, //0x1.fc2p-1,0x1.fc3p-1(0x42)
{0x1.01ep+0, -0x1.58fc273c52cc4p-7, 0x1.894a67f33bffcp-62, 0}, //0x1.fc3p-1,0x1.fc4p-1(0x43)
{0x1.01ep+0, -0x1.58fc273c52cc4p-7, 0x1.894a67f33bffcp-62, 0}, //0x1.fc4p-1,0x1.fc5p-1(0x44)
{0x1.01dp+0, -0x1.4d86a43264a3cp-7, -0x1.0244c310c007bp-62, 0}, //0x1.fc5p-1,0x1.fc6p-1(0x45)
{0x1.01dp+0, -0x1.4d86a43264a3cp-7, -0x1.0244c310c007bp-62, 0}, //0x1.fc6p-1,0x1.fc7p-1(0x46)
{0x1.01cp+0, -0x1.42106b1499209p-7, 0x1.eb240444ece78p-62, 0}, //0x1.fc7p-1,0x1.fc8p-1(0x47)
{0x1.01cp+0, -0x1.42106b1499209p-7, 0x1.eb240444ece78p-62, 0}, //0x1.fc8p-1,0x1.fc9p-1(0x48)
{0x1.01bp+0, -0x1.36997bcc54a26p-7, -0x1.71334e8e83316p-61, 0}, //0x1.fc9p-1,0x1.fcap-1(0x49)
{0x1.01bp+0, -0x1.36997bcc54a26p-7, -0x1.71334e8e83316p-61, 0}, //0x1.fcap-1,0x1.fcbp-1(0x4a)
{0x1.01ap+0, -0x1.2b21d642f752ep-7, -0x1.3e302631f59aep-61, 0}, //0x1.fcbp-1,0x1.fccp-1(0x4b)
{0x1.01ap+0, -0x1.2b21d642f752ep-7, -0x1.3e302631f59aep-61, 0}, //0x1.fccp-1,0x1.fcdp-1(0x4c)
{0x1.019p+0, -0x1.1fa97a61dd246p-7, 0x1.f3ba803d25558p-66, 0}, //0x1.fcdp-1,0x1.fcep-1(0x4d)
{0x1.019p+0, -0x1.1fa97a61dd246p-7, 0x1.f3ba803d25558p-66, 0}, //0x1.fcep-1,0x1.fcfp-1(0x4e)
{0x1.018p+0, -0x1.143068125dd0ep-7, 0x1.04f44238bc778p-65, 0}, //0x1.fcfp-1,0x1.fdp-1(0x4f)
{0x1.018p+0, -0x1.143068125dd0ep-7, 0x1.04f44238bc778p-65, 0}, //0x1.fdp-1,0x1.fd1p-1(0x50)
{0x1.017p+0, -0x1.08b69f3dccd91p-7, -0x1.6ac13536c8bbcp-61, 0}, //0x1.fd1p-1,0x1.fd2p-1(0x51)
{0x1.017p+0, -0x1.08b69f3dccd91p-7, -0x1.6ac13536c8bbcp-61, 0}, //0x1.fd2p-1,0x1.fd3p-1(0x52)
{0x1.016p+0, -0x1.fa783f9af306ap-8, 0x1.c0241958bacc5p-62, 0}, //0x1.fd3p-1,0x1.fd4p-1(0x53)
{0x1.016p+0, -0x1.fa783f9af306ap-8, 0x1.c0241958bacc5p-62, 0}, //0x1.fd4p-1,0x1.fd5p-1(0x54)
{0x1.015p+0, -0x1.e381d3555db4cp-8, 0x1.dd4fb2903732p-62, 0}, //0x1.fd5p-1,0x1.fd6p-1(0x55)
{0x1.015p+0, -0x1.e381d3555db4cp-8, 0x1.dd4fb2903732p-62, 0}, //0x1.fd6p-1,0x1.fd7p-1(0x56)
{0x1.014p+0, -0x1.cc89f97d67594p-8, 0x1.b7e678c26f70dp-62, 0}, //0x1.fd7p-1,0x1.fd8p-1(0x57)
{0x1.014p+0, -0x1.cc89f97d67594p-8, 0x1.b7e678c26f70dp-62, 0}, //0x1.fd8p-1,0x1.fd9p-1(0x58)
{0x1.013p+0, -0x1.b590b1e59515bp-8, 0x1.572d272c24846p-63, 0}, //0x1.fd9p-1,0x1.fdap-1(0x59)
{0x1.013p+0, -0x1.b590b1e59515bp-8, 0x1.572d272c24846p-63, 0}, //0x1.fdap-1,0x1.fdbp-1(0x5a)
{0x1.012p+0, -0x1.9e95fc60638e7p-8, 0x1.3dbbb11c10fefp-64, 0}, //0x1.fdbp-1,0x1.fdcp-1(0x5b)
{0x1.012p+0, -0x1.9e95fc60638e7p-8, 0x1.3dbbb11c10fefp-64, 0}, //0x1.fdcp-1,0x1.fddp-1(0x5c)
{0x1.011p+0, -0x1.8799d8c046e88p-8, -0x1.29fd6ab7d79b7p-64, 0}, //0x1.fddp-1,0x1.fdep-1(0x5d)
{0x1.011p+0, -0x1.8799d8c046e88p-8, -0x1.29fd6ab7d79b7p-64, 0}, //0x1.fdep-1,0x1.fdfp-1(0x5e)
{0x1.01p+0, -0x1.709c46d7aac77p-8, -0x1.2b66f4924be11p-62, 0}, //0x1.fdfp-1,0x1.fep-1(0x5f)
{0x1.01p+0, -0x1.709c46d7aac77p-8, -0x1.2b66f4924be11p-62, 0}, //0x1.fep-1,0x1.fe1p-1(0x60)
{0x1.00fp+0, -0x1.599d4678f24b4p-8, -0x1.e3dc463e109b4p-62, 0}, //0x1.fe1p-1,0x1.fe2p-1(0x61)
{0x1.00fp+0, -0x1.599d4678f24b4p-8, -0x1.e3dc463e109b4p-62, 0}, //0x1.fe2p-1,0x1.fe3p-1(0x62)
{0x1.00ep+0, -0x1.429cd776780e4p-8, -0x1.cdbb4dd53c3bbp-62, 0}, //0x1.fe3p-1,0x1.fe4p-1(0x63)
{0x1.00ep+0, -0x1.429cd776780e4p-8, -0x1.cdbb4dd53c3bbp-62, 0}, //0x1.fe4p-1,0x1.fe5p-1(0x64)
{0x1.00dp+0, -0x1.2b9af9a28e22fp-8, -0x1.1e2e767561e5cp-65, 0}, //0x1.fe5p-1,0x1.fe6p-1(0x65)
{0x1.00dp+0, -0x1.2b9af9a28e22fp-8, -0x1.1e2e767561e5cp-65, 0}, //0x1.fe6p-1,0x1.fe7p-1(0x66)
{0x1.00cp+0, -0x1.1497accf7e11dp-8, 0x1.1160c482db0e6p-66, 0}, //0x1.fe7p-1,0x1.fe8p-1(0x67)
{0x1.00cp+0, -0x1.1497accf7e11dp-8, 0x1.1160c482db0e6p-66, 0}, //0x1.fe8p-1,0x1.fe9p-1(0x68)
{0x1.00bp+0, -0x1.fb25e19f11aecp-9, 0x1.b6f37deb3137p-65, 0}, //0x1.fe9p-1,0x1.feap-1(0x69)
{0x1.00bp+0, -0x1.fb25e19f11aecp-9, 0x1.b6f37deb3137p-65, 0}, //0x1.feap-1,0x1.febp-1(0x6a)
{0x1.00ap+0, -0x1.cd198ae9cdc3dp-9, 0x1.144bb17b9ac9cp-63, 0}, //0x1.febp-1,0x1.fecp-1(0x6b)
{0x1.00ap+0, -0x1.cd198ae9cdc3dp-9, 0x1.144bb17b9ac9cp-63, 0}, //0x1.fecp-1,0x1.fedp-1(0x6c)
{0x1.009p+0, -0x1.9f0a5523901ebp-9, 0x1.60545d61b9512p-63, 0}, //0x1.fedp-1,0x1.feep-1(0x6d)
{0x1.009p+0, -0x1.9f0a5523901ebp-9, 0x1.60545d61b9512p-63, 0}, //0x1.feep-1,0x1.fefp-1(0x6e)
{0x1.008p+0, -0x1.70f83ff0a7565p-9, 0x1.ce2b9892e27e9p-64, 0}, //0x1.fefp-1,0x1.ffp-1(0x6f)
{0x1.008p+0, -0x1.70f83ff0a7565p-9, 0x1.ce2b9892e27e9p-64, 0}, //0x1.ffp-1,0x1.ff1p-1(0x70)
{0x1.007p+0, -0x1.42e34af550d87p-9, 0x1.574c3ce9b89b1p-63, 0}, //0x1.ff1p-1,0x1.ff2p-1(0x71)
{0x1.007p+0, -0x1.42e34af550d87p-9, 0x1.574c3ce9b89b1p-63, 0}, //0x1.ff2p-1,0x1.ff3p-1(0x72)
{0x1.006p+0, -0x1.14cb75d5b8e54p-9, 0x1.3ab2c932b8b0ap-64, 0}, //0x1.ff3p-1,0x1.ff4p-1(0x73)
{0x1.006p+0, -0x1.14cb75d5b8e54p-9, 0x1.3ab2c932b8b0ap-64, 0}, //0x1.ff4p-1,0x1.ff5p-1(0x74)
{0x1.005p+0, -0x1.cd61806bf5166p-10, -0x1.460b177a58742p-64, 0}, //0x1.ff5p-1,0x1.ff6p-1(0x75)
{0x1.005p+0, -0x1.cd61806bf5166p-10, -0x1.460b177a58742p-64, 0}, //0x1.ff6p-1,0x1.ff7p-1(0x76)
{0x1.004p+0, -0x1.712653743f454p-10, -0x1.fa9f94392637bp-66, 0}, //0x1.ff7p-1,0x1.ff8p-1(0x77)
{0x1.004p+0, -0x1.712653743f454p-10, -0x1.fa9f94392637bp-66, 0}, //0x1.ff8p-1,0x1.ff9p-1(0x78)
{0x1.003p+0, -0x1.14e5640c4193p-10, 0x1.3db883c072f72p-64, 0}, //0x1.ff9p-1,0x1.ffap-1(0x79)
{0x1.003p+0, -0x1.14e5640c4193p-10, 0x1.3db883c072f72p-64, 0}, //0x1.ffap-1,0x1.ffbp-1(0x7a)
{0x1.002p+0, -0x1.713d62f7957c3p-11, -0x1.5ea75a74def03p-68, 0}, //0x1.ffbp-1,0x1.ffcp-1(0x7b)
{0x1.002p+0, -0x1.713d62f7957c3p-11, -0x1.5ea75a74def03p-68, 0}, //0x1.ffcp-1,0x1.ffdp-1(0x7c)
{0x1.001p+0, -0x1.7148ec2a1bfc9p-12, 0x1.c7bc3fe53cd94p-66, 0}, //0x1.ffdp-1,0x1.ffep-1(0x7d)
{0x1p+0, 0x0p+0, 0x0p+0, 0}, //0x1.ffep-1,0x1.fffp-1(0x7e)
{0x1p+0, 0x0p+0, 0x0p+0, 0}, //0x1.fffp-1,0x1p+0(0x7f)
};

/* acc_coarsetbl[i] holds a tint approximating -log2(coarsetbl[i].r * 2^z[i])
   with relative error at most 2^-256, where z[i] = coarsetbl[i].z */
static const qint64_t acc_coarsetbl[128] = {
    {.hh = 0x0, .hl = 0x0, .lh = 0x0, .ll = 0x0, .ex = 0, .sgn = 0x0},
    {.hh = 0x8b510f105052285e, .hl = 0x49a09c72f783d310, .lh = 0x4c914d6a61f49b08, .ll = 0xfc7d870b752b078d, .ex = -6, .sgn = 0x0},
    {.hh = 0xe91d7e2489cfc4de, .hl = 0x6d73dea0942a7bca, .lh = 0xeda21a30e2f3919f, .ll = 0x2a2fa6a536f0a452, .ex = -6, .sgn = 0x0},
    {.hh = 0xa3d5039abb82795a, .hl = 0x51cc6227b892ff8c, .lh = 0x35a59ca13fd6e924, .ll = 0xbbdf8233d87d5bc0, .ex = -5, .sgn = 0x0},
    {.hh = 0xc789adc083c88cea, .hl = 0x4199ad66d4606b1, .lh = 0x1f3cf089b6f60e93, .ll = 0x7028f86ad900887d, .ex = -5, .sgn = 0x0},
    {.hh = 0xf77bc92845b4eb09, .hl = 0xb992dcd8ef4b5434, .lh = 0x956b49a6fb8e9178, .ll = 0xa36713991634e90c, .ex = -5, .sgn = 0x0},
    {.hh = 0x93e925d74126d610, .hl = 0x50fdb57412a4804, .lh = 0x6d477eabaf9e7231, .ll = 0x8e1aba642aea3e99, .ex = -4, .sgn = 0x0},
    {.hh = 0xa62b07f3457c4070, .hl = 0x50799beaaab2940c, .lh = 0x18cf448bef176a47, .ll = 0x5a862230522a2ea1, .ex = -4, .sgn = 0x0},
    {.hh = 0xbeb024b67dda6339, .hl = 0xda288fc615a727db, .lh = 0xaad60b1bf6bcd429, .ll = 0xe9fded86733d3ca7, .ex = -4, .sgn = 0x0},
    {.hh = 0xd13666ccc0c2944c, .hl = 0xa13eeb0b64fdd38f, .lh = 0xb851b68e7a69121f, .ll = 0x3482a3e6ffb85d19, .ex = -4, .sgn = 0x0},
    {.hh = 0xea180512926a0bb5, .hl = 0x9a5dae441067744d, .lh = 0x672772d3e3fef542, .ll = 0xefa2f5f77af0e9d, .ex = -4, .sgn = 0x0},
    {.hh = 0xfce4aee0e88b2749, .hl = 0x9596a8e2e84c8f45, .lh = 0x7c3feaa2020e02ee, .ll = 0x96924afd238c8c90, .ex = -4, .sgn = 0x0},
    {.hh = 0x8b12c98c36d37e20, .hl = 0xf0243d6a2e6be6ae, .lh = 0x365c895bab1cf0fd, .ll = 0x726bc0758570d265, .ex = -3, .sgn = 0x0},
    {.hh = 0x949d61ee0d33432f, .hl = 0x2c33fc5e114dc8d3, .lh = 0x3239b5517d75afd2, .ll = 0xc91ae4316704c75f, .ex = -3, .sgn = 0x0},
    {.hh = 0x9e37db2866f2850b, .hl = 0x22563c9ed9462091, .lh = 0x6c98f8a6d53de3e6, .ll = 0x2d83604d2ba27b79, .ex = -3, .sgn = 0x0},
    {.hh = 0xa7e26a6cdd989af8, .hl = 0x5862e570d5efa0fc, .lh = 0xda477320a297d13d, .ll = 0x77c9171c423196e, .ex = -3, .sgn = 0x0},
    {.hh = 0xb19d45fa1be70855, .hl = 0x3eb8023eed65d601, .lh = 0x656701a2001a0791, .ll = 0x8ceeaa12e75b6fc4, .ex = -3, .sgn = 0x0},
    {.hh = 0xbeb024b67dda6339, .hl = 0xda288fc615a727db, .lh = 0xaad60b1bf6bcd429, .ll = 0xe9fded86733d3ca7, .ex = -3, .sgn = 0x0},
    {.hh = 0xc891e0a946366f7a, .hl = 0x6c66f30966572dc5, .lh = 0x630fb7044d829560, .ll = 0xdd6311f99f92e6c0, .ex = -3, .sgn = 0x0},
    {.hh = 0xd284a5aa69414202, .hl = 0x76dd59d7241fa312, .lh = 0x681a6e20d4a0b338, .ll = 0xb8b88c3ad31b5684, .ex = -3, .sgn = 0x0},
    {.hh = 0xdc88aedc1d1ee969, .hl = 0xa95f528f2c754f3d, .lh = 0x122ba0a2e1a73fa6, .ll = 0x42224ca9e7cc3674, .ex = -3, .sgn = 0x0},
    {.hh = 0xe69e389698884992, .hl = 0xeeaf409cc886903f, .lh = 0x80ca8b19889a5864, .ll = 0xe8b8ee0c0e5af23e, .ex = -3, .sgn = 0x0},
    {.hh = 0xf0c580709891e833, .hl = 0x7eebe11bf1f5f771, .lh = 0xbe09d3d540a66df8, .ll = 0x74d922c3804f9985, .ex = -3, .sgn = 0x0},
    {.hh = 0xf7945566b9118906, .hl = 0x313e79cf1dc34ffd, .lh = 0x42635886323b20aa, .ll = 0xc9481f9c6393327d, .ex = -3, .sgn = 0x0},
    {.hh = 0x80ecdde7d30ea2ed, .hl = 0x132880194144b02b, .lh = 0xb4d4431bd7f6593, .ll = 0xab8638dbc6a50eb, .ex = -2, .sgn = 0x0},
    {.hh = 0x8618c576ff9e03b3, .hl = 0x36c24b73a6a84832, .lh = 0x3ef893cb05109d79, .ll = 0xf75050e9572d685, .ex = -2, .sgn = 0x0},
    {.hh = 0x8b4e029b1f8ac391, .hl = 0xa87c02eaf36e2c28, .lh = 0x81e4083228010589, .ll = 0xbcb6ea2e57d71f23, .ex = -2, .sgn = 0x0},
    {.hh = 0x908cb743a39e8597, .hl = 0x80f0cdc6bc25e9ff, .lh = 0x60480710cfcc2ca8, .ll = 0xdc4f2d74ffc7277c, .ex = -2, .sgn = 0x0},
    {.hh = 0x94112ddaf3251f47, .hl = 0x5585fbd17de382f1, .lh = 0x7a743db94d036e6b, .ll = 0x56556c26c58d246e, .ex = -2, .sgn = 0x0},
    {.hh = 0x995ff71b8773432d, .hl = 0x124bc6f1acf95dc3, .lh = 0xc616f85adff31270, .ll = 0xd154b69f22fa89fd, .ex = -2, .sgn = 0x0},
    {.hh = 0x9eb895fce4ef7663, .hl = 0x11b9141c5d31ad80, .lh = 0xac1494e36fb0f309, .ll = 0x9269dde3c74632de, .ex = -2, .sgn = 0x0},
    {.hh = 0xa24e88af7bec3b63, .hl = 0xdb8549508ba15e1c, .lh = 0x9b4f95dc7d59bdcf, .ll = 0xa0a55416e9662026, .ex = -2, .sgn = 0x0},
    {.hh = 0xa7b7dd96762cc3c7, .hl = 0x2742d7296a39eed6, .lh = 0x217738c357a7a04e, .ll = 0x75ec4ed1b7686124, .ex = -2, .sgn = 0x0},
    {.hh = 0xab591735abc724e4, .hl = 0xf359c5544bc5e133, .lh = 0x82c21c939fc1325c, .ll = 0x4840c9c4e9400f24, .ex = -2, .sgn = 0x0},
    {.hh = 0xb0d38be560cc188a, .hl = 0xf80f47efb56b351b, .lh = 0xb89314b60711018b, .ll = 0x5fdc3cf6a285d2e9, .ex = -2, .sgn = 0x0},
    {.hh = 0xb4805441b686a83a, .hl = 0x79af29ddc116c801, .lh = 0x6eeebf9673787119, .ll = 0xeaf8f616803038fd, .ex = -2, .sgn = 0x0},
    {.hh = 0xba0c5675df8c75b2, .hl = 0x8001fd98d1557c71, .lh = 0x1482ec1ef7ca2f90, .ll = 0xc72a5b83070a1c9e, .ex = -2, .sgn = 0x0},
    {.hh = 0xbdc4f8167955698f, .hl = 0x89e2eb553b279b3c, .lh = 0xef4a4e02f47c2c46, .ll = 0xfbba8311725c3df8, .ex = -2, .sgn = 0x0},
    {.hh = 0xc1826c8608fe9951, .hl = 0xd58525aad392ca4f, .lh = 0xcfd080244236ad39, .ll = 0xbe059904992c5eba, .ex = -2, .sgn = 0x0},
    {.hh = 0xc727c1fd0a2f6d7e, .hl = 0x41e3d18751733527, .lh = 0xed0e324fc4975d37, .ll = 0x122e8396b06a4fb7, .ex = -2, .sgn = 0x0},
    {.hh = 0xcaf17cda8f827179, .hl = 0x3366c239cacf7517, .lh = 0x590817d4082d70cf, .ll = 0x342c821049a4393, .ex = -2, .sgn = 0x0},
    {.hh = 0xcec0375e4c90dc60, .hl = 0xdc5befeb9494d34d, .lh = 0x42e05994f1b60f05, .ll = 0xa8d7865d3bbd75f7, .ex = -2, .sgn = 0x0},
    {.hh = 0xd47fcb8c0852f0c0, .hl = 0xbfe9dbebf2e8a45d, .lh = 0xb61832b8bb4c9f7f, .ll = 0x834df65b40b7c12, .ex = -2, .sgn = 0x0},
    {.hh = 0xd85b3fa7a3407fa8, .hl = 0x7b11f1c5160c515c, .lh = 0xf4b1772f673312a, .ll = 0x17edfe2b4d4e3835, .ex = -2, .sgn = 0x0},
    {.hh = 0xdc3be2bd8d837f7f, .hl = 0x1339e5677ec44dd0, .lh = 0xc794a2efbe7ab6, .ll = 0xa71b9c0fc3f1447, .ex = -2, .sgn = 0x0},
    {.hh = 0xe021c2cf17ed9bdb, .hl = 0xea2b8c7bb0ee9c8a, .lh = 0xb0bb4d9a2f030ee7, .ll = 0xa0f251f5e20a05c1, .ex = -2, .sgn = 0x0},
    {.hh = 0xe40cee16a2ff21c4, .hl = 0xaec562332791fe38, .lh = 0x2a72aa9a3e20eb30, .ll = 0x3359f6c3601f500c, .ex = -2, .sgn = 0x0},
    {.hh = 0xe9f7bbb6a1ff9f87, .hl = 0x5321c0298d15f3d2, .lh = 0x624494be0ef7c695, .ll = 0x6b13b4ac9757705c, .ex = -2, .sgn = 0x0},
    {.hh = 0xedf062c61e7f8d2b, .hl = 0x52e9fba2cba2db9a, .lh = 0x1056bda2251e35f4, .ll = 0x450a9df31dbeb0ae, .ex = -2, .sgn = 0x0},
    {.hh = 0xf1ee88ab283eeec5, .hl = 0x15435db02db326a2, .lh = 0x2d1e5b6b25da63fa, .ll = 0xc8bb7f9b8e8a3761, .ex = -2, .sgn = 0x0},
    {.hh = 0xf5f23cb071e043ff, .hl = 0x272934312fad34bd, .lh = 0x1a452045d680aa7c, .ll = 0xe00f6738f7c5458d, .ex = -2, .sgn = 0x0},
    {.hh = 0xf9fb8e60db14dc16, .hl = 0x6e0e0c6803dbc95b, .lh = 0x3eea62e24b63223e, .ll = 0xde72339c3be5d025, .ex = -2, .sgn = 0x0},
    {.hh = 0xfe0a8d88d9b200dc, .hl = 0xd40842e69d954960, .lh = 0xbc4c03dbb7127a10, .ll = 0xded667f1c89607ba, .ex = -2, .sgn = 0x0},
    {.hh = 0xfde0b5c81340511d, .hl = 0x46ccc53c2779af92, .lh = 0x67ab76d6a54835aa, .ll = 0xcfb1c475d9097da1, .ex = -2, .sgn = 0x1},
    {.hh = 0xf9c62b3de62a0687, .hl = 0xf1be9685f6adf04a, .lh = 0xeab1edd281db7846, .ll = 0xcd4feb19320ee0cb, .ex = -2, .sgn = 0x1},
    {.hh = 0xf5a5c23e8ade729f, .hl = 0x2e4f301ebd9161b8, .lh = 0x501611ccab3b2f47, .ll = 0x1bffd6982b00d51, .ex = -2, .sgn = 0x1},
    {.hh = 0xf17f69e84b94c06f, .hl = 0x912ab9d10aad739d, .lh = 0x205efb04d957b161, .ll = 0x398375ed28b6e5f9, .ex = -2, .sgn = 0x1},
    {.hh = 0xed531110327dc809, .hl = 0x3a52b8ab08db739b, .lh = 0x76c249f482761e55, .ll = 0x8a86f75d382c61d3, .ex = -2, .sgn = 0x1},
    {.hh = 0xe920a6405f93ea90, .hl = 0xadf6a54a7a4cb523, .lh = 0x17a06f7aee270f12, .ll = 0x160cab2fc0e301cd, .ex = -2, .sgn = 0x1},
    {.hh = 0xe7052491d2c3e64a, .hl = 0xe851773d02c9055c, .lh = 0x852aa737e1da47e, .ll = 0x931714436890c845, .ex = -2, .sgn = 0x1},
    {.hh = 0xe2c97d694adab3f3, .hl = 0xf72a5777998629e0, .lh = 0x55986623a20f5e8f, .ll = 0x37de0a9a289c0655, .ex = -2, .sgn = 0x1},
    {.hh = 0xde87974f3c81855a, .hl = 0x216719008b614534, .lh = 0x88bf5b6cc1f08423, .ll = 0xed612d66a752f2f2, .ex = -2, .sgn = 0x1},
    {.hh = 0xda3f5fb9c4150520, .hl = 0xa377c7ec513c756e, .lh = 0x29500bdc84e32ff8, .ll = 0x6792386e2c59822d, .ex = -2, .sgn = 0x1},
    {.hh = 0xd5f0c3cbf8fa470d, .hl = 0x2392aac62deb8f0d, .lh = 0xc7a555f9dc0adbd7, .ll = 0x576f236f846dc6ad, .ex = -2, .sgn = 0x1},
    {.hh = 0xd19bb053fb0284eb, .hl = 0xe206bcbcf62d8fee, .lh = 0x6003a9e7214269a5, .ll = 0x1ffdf49813df47d6, .ex = -2, .sgn = 0x1},
    {.hh = 0xcf6eb3acd92efc46, .hl = 0xd8e7ce35765cbcd4, .lh = 0xc0fd57324b61c2f2, .ll = 0x1d82505fc51b97c, .ex = -2, .sgn = 0x1},
    {.hh = 0xcb0fc8293a04dc67, .hl = 0xacebd6e326ca9f2c, .lh = 0xb42a6c6c030003b2, .ll = 0x20b668cabdc98bc9, .ex = -2, .sgn = 0x1},
    {.hh = 0xc6aa339dae1b8d59, .hl = 0xe8492d6d9fc1bb34, .lh = 0x3d8cce6ab957aede, .ll = 0xbd323b060c96ea5e, .ex = -2, .sgn = 0x1},
    {.hh = 0xc474e39705912d25, .hl = 0xb3252646d4dd5887, .lh = 0xd8edb8fe65f8cedf, .ll = 0x3b1397df90ec5633, .ex = -2, .sgn = 0x1},
    {.hh = 0xc0052b18b0e2a195, .hl = 0x75b04fa6fbd6446c, .lh = 0x2f637f249351c25a, .ll = 0x70b8ef1f38fbd09a, .ex = -2, .sgn = 0x1},
    {.hh = 0xbb8e95d3f7d9df23, .hl = 0x7f66a891253fe387, .lh = 0x923094a7846dddac, .ll = 0x9a2fc05858eb6b02, .ex = -2, .sgn = 0x1},
    {.hh = 0xb7110e6ce866f2bc, .hl = 0x6a905a27b81e2219, .lh = 0x3f120a0650bedb03, .ll = 0x47ae3f2fd98cc0c3, .ex = -2, .sgn = 0x1},
    {.hh = 0xb4cfa92466a5c346, .hl = 0x2a42a1a5b7dbe193, .lh = 0xc9e1a4c22a4ae43a, .ll = 0xb35f8d2691102ee1, .ex = -2, .sgn = 0x1},
    {.hh = 0xb0478da14a456cb7, .hl = 0x8073a9032e045709, .lh = 0xd0ae67889b47c278, .ll = 0x4a1611690b7dcfd3, .ex = -2, .sgn = 0x1},
    {.hh = 0xae00d1cfdeb43cfd, .hl = 0x589050345d6e89, .lh = 0x279f351d12cd8203, .ll = 0xdf2c82692fd20fb9, .ex = -2, .sgn = 0x1},
    {.hh = 0xa96defe264b59bee, .hl = 0x7b0730fe4da965de, .lh = 0xefde1e4adaa6732d, .ll = 0xd33538108d0b03d0, .ex = -2, .sgn = 0x1},
    {.hh = 0xa4d3c25e68dc57f2, .hl = 0x495fb7fa6d7eda66, .lh = 0xcb62aff1bd9d6a74, .ll = 0x8db56404173c2ce8, .ex = -2, .sgn = 0x1},
    {.hh = 0xa283e7f6ea7e1ca6, .hl = 0xad04ffe637187bbc, .lh = 0x8896b04adf7910c5, .ll = 0x54c225b9d2623c93, .ex = -2, .sgn = 0x1},
    {.hh = 0x9dde9d050ee7d4ac, .hl = 0x186e86d31a4ea054, .lh = 0x2e101e04ff719f2d, .ll = 0x51e68780318a2e3d, .ex = -2, .sgn = 0x1},
    {.hh = 0x9b892675266f66cc, .hl = 0x899b64b03f7230dc, .lh = 0x826ede8c25a96173, .ll = 0x4a0fa2d8242f7100, .ex = -2, .sgn = 0x1},
    {.hh = 0x96d887e26cd57b78, .hl = 0x9bd1ec6379e6e3b8, .lh = 0xe2ce02e2f9138241, .ll = 0x5635b04e24698a94, .ex = -2, .sgn = 0x1},
    {.hh = 0x947d59ad99341b18, .hl = 0x1d0b52117cb07dce, .lh = 0x1691cb8928b8232a, .ll = 0x8aff2d7d8fa56579, .ex = -2, .sgn = 0x1},
    {.hh = 0x8fc12fb6c470995f, .hl = 0x43469fbe6e9880c3, .lh = 0xa7e9e3dc01672bba, .ll = 0x5d84af52ef73054e, .ex = -2, .sgn = 0x1},
    {.hh = 0x8d602d948f838294, .hl = 0x639c36fc650d030e, .lh = 0xd8e69396967f7b59, .ll = 0xff2dddac97b0e3fc, .ex = -2, .sgn = 0x1},
    {.hh = 0x88983ed6985bae58, .hl = 0x4b82d3cad274fe0c, .lh = 0xee7361fe84ffe24c, .ll = 0x8c5b87f52fd328a1, .ex = -2, .sgn = 0x1},
    {.hh = 0x86314baaa1547527, .hl = 0xd8fd20c17007a8c1, .lh = 0x3f2559b463e86050, .ll = 0xf0f1e920bda74c47, .ex = -2, .sgn = 0x1},
    {.hh = 0x83c856dd81804b78, .hl = 0x18d34ceaa2dd6ccc, .lh = 0x28709483ed0bc032, .ll = 0x81ded1c8948c22ca, .ex = -2, .sgn = 0x1},
    {.hh = 0xfde0b5c81340511d, .hl = 0x46ccc53c2779af92, .lh = 0x67ab76d6a54835aa, .ll = 0xcfb1c475d9097da1, .ex = -3, .sgn = 0x1},
    {.hh = 0xf90299c904793a3b, .hl = 0xa953398c67527c59, .lh = 0xce01e8f809fb6dd5, .ll = 0xaafae855a5c9c6e, .ex = -3, .sgn = 0x1},
    {.hh = 0xef39ff1d8a40770d, .hl = 0xf2139e68f20f8bf9, .lh = 0x35baacd90f8bff1b, .ll = 0xbe7d0952cce3e144, .ex = -3, .sgn = 0x1},
    {.hh = 0xea4f726192cb7e47, .hl = 0xa5ab2811d02a20df, .lh = 0xc15a5a557fdc6ad4, .ll = 0x266bd144f4d9bb7d, .ex = -3, .sgn = 0x1},
    {.hh = 0xe560b1e3b86e44b6, .hl = 0x2652c588f1c96f19, .lh = 0x7073b6bfefa1224f, .ll = 0x14686a6c5ff016bd, .ex = -3, .sgn = 0x1},
    {.hh = 0xdb7678bafcaf4b5f, .hl = 0x6c66717da3df80ca, .lh = 0xb53afe88a06e6873, .ll = 0xf8213b11b3308bed, .ex = -3, .sgn = 0x1},
    {.hh = 0xd67af16da7649f7f, .hl = 0x8f65e00c1b1a5a9, .lh = 0x415f750a1f88bc5, .ll = 0x57b1329094fba1a0, .ex = -3, .sgn = 0x1},
    {.hh = 0xd17b191905c35651, .hl = 0xc429392bd103b8af, .lh = 0x5b81a0fc96134fab, .ll = 0x73e73ca2bbb172b, .ex = -3, .sgn = 0x1},
    {.hh = 0xc76e5741a95b5dae, .hl = 0x6a10cca4cda6f56f, .lh = 0x7a4193f151aebc12, .ll = 0x247c2a5430ef3b53, .ex = -3, .sgn = 0x1},
    {.hh = 0xc2615e81781d97ee, .hl = 0x9124773b1d4ab87b, .lh = 0xeb65da57edfee699, .ll = 0x27b0d0bf59bc05e6, .ex = -3, .sgn = 0x1},
    {.hh = 0xbd4ff63e82eef78b, .hl = 0xf26d07705e32dc2c, .lh = 0x2f869c118767d779, .ll = 0x5199734daf39c6dd, .ex = -3, .sgn = 0x1},
    {.hh = 0xb31fb7d64898b3e6, .hl = 0x629c130a22bad61e, .lh = 0x5283e7d58e93fcc2, .ll = 0x4922424ff28c6bb8, .ex = -3, .sgn = 0x1},
    {.hh = 0xae00d1cfdeb43cfd, .hl = 0x589050345d6e89, .lh = 0x279f351d12cd8203, .ll = 0xdf2c82692fd20fb9, .ex = -3, .sgn = 0x1},
    {.hh = 0xa8dd5c83d2e45245, .hl = 0x8044c2dfbfd2e54f, .lh = 0x613ea92ca7435531, .ll = 0x7eb516d6274a5e70, .ex = -3, .sgn = 0x1},
    {.hh = 0xa3b54fcc1fba6989, .hl = 0xc74a0b21fb609f75, .lh = 0x6d9e3e274454008c, .ll = 0x86b50a35a580605e, .ex = -3, .sgn = 0x1},
    {.hh = 0x99574f13c570d0fa, .hl = 0x8f9603ad3a5d326c, .lh = 0xa9f8962637748dd9, .ll = 0x579c23d222f57221, .ex = -3, .sgn = 0x1},
    {.hh = 0x94214a583d31fc6b, .hl = 0xb455652111619632, .lh = 0xea3495efa5929e30, .ll = 0xe169eb9dd3e73455, .ex = -3, .sgn = 0x1},
    {.hh = 0x8ee68cbaa95bdaf5, .hl = 0x22a183c1cb0abad4, .lh = 0x3eea455a0d24eaa1, .ll = 0x88e253add7aa67c4, .ex = -3, .sgn = 0x1},
    {.hh = 0x89a70da448316ff9, .hl = 0xad20807c9996bec9, .lh = 0xede2c27d582dd47a, .ll = 0x70dca895b48a5463, .ex = -3, .sgn = 0x1},
    {.hh = 0xfe33507858052482, .hl = 0x69a31ca846f37fb2, .lh = 0x854df8cd8923479d, .ll = 0x843aeb746176fbc0, .ex = -4, .sgn = 0x1},
    {.hh = 0xf397608bfd2d90e5, .hl = 0xedaecee14f902752, .lh = 0xa1dc5b384b68c4f1, .ll = 0xe668d05cea069df1, .ex = -4, .sgn = 0x1},
    {.hh = 0xe8f1a71adc16d268, .hl = 0x59c7991e5f2c5786, .lh = 0x582d052e2de438ae, .ll = 0xf70b7be656258b60, .ex = -4, .sgn = 0x1},
    {.hh = 0xde4212056d5dd31d, .hl = 0x962d3728cbd5c3cb, .lh = 0x20e2840871dc1065, .ll = 0x4d5031be7b9c6526, .ex = -4, .sgn = 0x1},
    {.hh = 0xd3888ef9a4249f5a, .hl = 0x22c0f1de169d8930, .lh = 0x4eaddd47f55f9e80, .ll = 0xc0680f0890cc4ff1, .ex = -4, .sgn = 0x1},
    {.hh = 0xc8c50b72319ad573, .hl = 0x91924a6d9d1d1904, .lh = 0x6b227370f7cb86bd, .ll = 0x9e3e2d3b2a956fb0, .ex = -4, .sgn = 0x1},
    {.hh = 0xb31fb7d64898b3e6, .hl = 0x629c130a22bad61e, .lh = 0x5283e7d58e93fcc2, .ll = 0x4922424ff28c6bb8, .ex = -4, .sgn = 0x1},
    {.hh = 0xa83dc1b019ddb6a7, .hl = 0x969bdb4d16a214f6, .lh = 0x3ca4d4f86091cf70, .ll = 0xc31c3c6b7edfcc63, .ex = -4, .sgn = 0x1},
    {.hh = 0x9d517ee93f8e16c0, .hl = 0x268890da5313b536, .lh = 0xa4685f1e2ede2fdd, .ll = 0xd45b174bec66e2cb, .ex = -4, .sgn = 0x1},
    {.hh = 0x925adbf09ad1e44d, .hl = 0x1679a8afb2d05b6d, .lh = 0xce48ee52e2ee9669, .ll = 0x801fecf7d206315f, .ex = -4, .sgn = 0x1},
    {.hh = 0x8759c4fd14fcd59e, .hl = 0x7ba5d5ccc90b8335, .lh = 0xc8a879e3eee911a8, .ll = 0xbdf35c07d56af5d8, .ex = -4, .sgn = 0x1},
    {.hh = 0xf89c4c19929cfd0e, .hl = 0x6835ddbcad87b2fa, .lh = 0xf2b454af3b147ac4, .ll = 0xdefd67e78ed844d5, .ex = -5, .sgn = 0x1},
    {.hh = 0xe26fd5c8555af7a7, .hl = 0xc7c34f31dc4142bd, .lh = 0x2b182fdaac375356, .ll = 0xfc2973b134e96a2a, .ex = -5, .sgn = 0x1},
    {.hh = 0xcc2dfe1a4a8ca305, .hl = 0x71da87bd08571f2, .lh = 0x4bf53dfcace32756, .ll = 0x87f3ceadfb286e2c, .ex = -5, .sgn = 0x1},
    {.hh = 0xb5d69bac77ec3989, .hl = 0xb03784b5be084906, .lh = 0x366f25ae368399c0, .ll = 0x63d2e2a20d79f0d0, .ex = -5, .sgn = 0x1},
    {.hh = 0x9f6984a342d13101, .hl = 0x3a5b81fc4947a943, .lh = 0x22e98e9e253de6b8, .ll = 0xc75aa2526d8be845, .ex = -5, .sgn = 0x1},
    {.hh = 0x88e68ea899a0976c, .hl = 0xa2827d49a3a979b, .lh = 0x57feea297d30b994, .ll = 0xd512972bdccecec0, .ex = -5, .sgn = 0x1},
    {.hh = 0xe49b1dd4287c3333, .hl = 0x7407b8ba69d85829, .lh = 0xf80336ae6c2bf102, .ll = 0xfa92b3474908a437, .ex = -6, .sgn = 0x1},
    {.hh = 0xb73cb42e16914c53, .hl = 0x713f108c0857ca30, .lh = 0x54bb796ddaa5803b, .ll = 0xc60ad64f441a2eb2, .ex = -6, .sgn = 0x1},
    {.hh = 0x89b188bd4bd8625d, .hl = 0xa0d364888a42362f, .lh = 0x398463853df15782, .ll = 0x384e58384963f44d, .ex = -6, .sgn = 0x1},
    {.hh = 0xb7f285b778428bfc, .hl = 0x71bd800bca7a220e, .lh = 0x66fb247932d20f2b, .ll = 0xebab210f09c0c362, .ex = -7, .sgn = 0x1},
    {.hh = 0x0, .hl = 0x0, .lh = 0x0, .ll = 0x0, .ex = 0, .sgn = 0x0},
};


/* acc_finetbl[i] holds a tint approximating -log2(finetbl[i].r) with
relative error at most 2^-256.
*/
static const qint64_t acc_finetbl[128] = {
    {.hh = 0x0, .hl = 0x0, .lh = 0x0, .ll = 0x0, .ex = 0, .sgn = 0x0},
    {.hh = 0x8a862ac30095c084, .hl = 0xe9bcfd0c62eaa2ca, .lh = 0x6c5f92c172efd68a, .ll = 0x502850f96434c589, .ex = -11, .sgn = 0x0},
    {.hh = 0xe6e6d4749883fbe3, .hl = 0x794b6437fb56343, .lh = 0xade811ee20b6fe4d, .ll = 0xd617a08e3d85ccd8, .ex = -11, .sgn = 0x0},
    {.hh = 0xa1a6a2a3113fe246, .hl = 0xc051d2c5f00a9bb8, .lh = 0x8fd0beffa5503d2f, .ll = 0xd33fb64b52a8d967, .ex = -10, .sgn = 0x0},
    {.hh = 0xcfdcbef858660da1, .hl = 0xb6cb28db8c065b43, .lh = 0xf7b1e1944191f5d5, .ll = 0x93cfa9fae2cce33d, .ex = -10, .sgn = 0x0},
    {.hh = 0xfe15bf96bc35246b, .hl = 0x13f6fda510aeec3b, .lh = 0x47a3ae2ce8279293, .ll = 0x46c6ee6ef425fe50, .ex = -10, .sgn = 0x0},
    {.hh = 0x9628d26d7448a43f, .hl = 0x9886a71b25a2085d, .lh = 0x2e5489158ce705ac, .ll = 0x94e04246af8813e5, .ex = -9, .sgn = 0x0},
    {.hh = 0xad483790cd6339fa, .hl = 0x94c99761b8eab3d7, .lh = 0xb5815e95a8e6aec9, .ll = 0x99c6616deccf1fa5, .ex = -9, .sgn = 0x0},
    {.hh = 0xc4690f63d0c66aa1, .hl = 0x7ef732b69334cf4f, .lh = 0xac7dad2d3d236e18, .ll = 0x9ad568a03bbba711, .ex = -9, .sgn = 0x0},
    {.hh = 0xdb8b5a14ee86965f, .hl = 0xa2f2bb9e156b0f36, .lh = 0xb54cc772d936de6d, .ll = 0xf013e48d739f19a1, .ex = -9, .sgn = 0x0},
    {.hh = 0xf2af17d29f7295c0, .hl = 0x7b3a20aa5289695e, .lh = 0xabd229732ebe993, .ll = 0xde30213971b61242, .ex = -9, .sgn = 0x0},
    {.hh = 0x84ea2465b28af4e7, .hl = 0x6fa5b7657b3239a7, .lh = 0x64bfff3025d02e24, .ll = 0xf2d6d2dfa3544bdc, .ex = -8, .sgn = 0x0},
    {.hh = 0x907d7696e4dd7671, .hl = 0xdfb994fc4e2917de, .lh = 0xec9f7e33764623, .ll = 0xfd3adb284633f890, .ex = -8, .sgn = 0x0},
    {.hh = 0x9c11829430368212, .hl = 0x58071e33dd1dc498, .lh = 0x540c5013b92ac19a, .ll = 0xbce78f6115a12afb, .ex = -8, .sgn = 0x0},
    {.hh = 0xa7a64874e27d68d9, .hl = 0x4333953d5aa887d4, .lh = 0x670877f99d2c08dd, .ll = 0xc73c26a70efe5ca4, .ex = -8, .sgn = 0x0},
    {.hh = 0xb33bc8504dfc33c4, .hl = 0x24b9a32167f99c98, .lh = 0xc34fb78004d80001, .ll = 0xa266fd7d00d3a88f, .ex = -8, .sgn = 0x0},
    {.hh = 0xbed2023dc960bd85, .hl = 0x5c68dc464dd695f5, .lh = 0x5c388629c2d5235f, .ll = 0xdf0714cb5f56f6c2, .ex = -8, .sgn = 0x0},
    {.hh = 0xca68f654afbdcca4, .hl = 0x5645af9f5973e9d1, .lh = 0xbcacb6adb9f3f551, .ll = 0x8ba6d07d37389125, .ex = -8, .sgn = 0x0},
    {.hh = 0xd600a4ac608c2df6, .hl = 0x4817dca07af21877, .lh = 0x8f928b05438f9d2c, .ll = 0xf50bfedc58f37567, .ex = -8, .sgn = 0x0},
    {.hh = 0xe1990d5c3fabcf6f, .hl = 0x9e042f9fd2388be3, .lh = 0x87baa1d89d8c90dd, .ll = 0x670c834c7672f8ef, .ex = -8, .sgn = 0x0},
    {.hh = 0xed32307bb564db4e, .hl = 0x379cef385edf3672, .lh = 0xdcd60e719fa118d7, .ll = 0x405e03fd31a344ac, .ex = -8, .sgn = 0x0},
    {.hh = 0xf8cc0e222e68d39c, .hl = 0x96e31789b174973f, .lh = 0x5781793da345ed21, .ll = 0xdfb06d5244d4d9d8, .ex = -8, .sgn = 0x0},
    {.hh = 0x823353338de9d707, .hl = 0x11609cee397740f2, .lh = 0xcb7a740b83b62ad7, .ll = 0x35af8cc38ba918c, .ex = -7, .sgn = 0x0},
    {.hh = 0x8800fcb0f996781a, .hl = 0x4f4bcc23842b04a6, .lh = 0xeede69b0dc464df4, .ll = 0xbb2f6fe3ef7980e0, .ex = -7, .sgn = 0x0},
    {.hh = 0x8dcf039517346607, .hl = 0x7c3feeb65aa00327, .lh = 0x4a2e2d5b30a8c268, .ll = 0xf3c134e74ecce6e1, .ex = -7, .sgn = 0x0},
    {.hh = 0x939d67eba5f49e78, .hl = 0xc7fed0304d420e7e, .lh = 0x44f4bff0c9bc956, .ll = 0x369a322f9a2c786b, .ex = -7, .sgn = 0x0},
    {.hh = 0x996c29c0673f9264, .hl = 0xb6fde0c7ed42b4d, .lh = 0x599f87e8e2add80c, .ll = 0x91165550b3cb82f8, .ex = -7, .sgn = 0x0},
    {.hh = 0x9f3b491f1eb5b4d8, .hl = 0x9712b05d5084f6f3, .lh = 0x24a21b33f0944f70, .ll = 0xbf78fc6d2cce8f72, .ex = -7, .sgn = 0x0},
    {.hh = 0xa50ac613923009f9, .hl = 0xf06455adebff9dcf, .lh = 0x20e7b0fe3e8e5406, .ll = 0x6d65a53fd72821fc, .ex = -7, .sgn = 0x0},
    {.hh = 0xaadaa0a989c0b627, .hl = 0x8f2fbf5bd55f7e91, .lh = 0xf4440a79030b6602, .ll = 0xd2b98aba34237aff, .ex = -7, .sgn = 0x0},
    {.hh = 0xb0aad8eccfb38d51, .hl = 0xabc9265386172074, .lh = 0x3669e5af860ce188, .ll = 0xbf192b97198ba344, .ex = -7, .sgn = 0x0},
    {.hh = 0xb67b6ee9308ea27b, .hl = 0x2f3bbe8e8d72abec, .lh = 0x2465c504fd423f43, .ll = 0x18cb456a71a50d87, .ex = -7, .sgn = 0x0},
    {.hh = 0x0, .hl = 0x0, .lh = 0x0, .ll = 0x0, .ex = 0, .sgn = 0x0},
    {.hh = 0x0, .hl = 0x0, .lh = 0x0, .ll = 0x0, .ex = 0, .sgn = 0x0},
    {.hh = 0x0, .hl = 0x0, .lh = 0x0, .ll = 0x0, .ex = 0, .sgn = 0x0},
    {.hh = 0x0, .hl = 0x0, .lh = 0x0, .ll = 0x0, .ex = 0, .sgn = 0x0},
    {.hh = 0x0, .hl = 0x0, .lh = 0x0, .ll = 0x0, .ex = 0, .sgn = 0x0},
    {.hh = 0x0, .hl = 0x0, .lh = 0x0, .ll = 0x0, .ex = 0, .sgn = 0x0},
    {.hh = 0x0, .hl = 0x0, .lh = 0x0, .ll = 0x0, .ex = 0, .sgn = 0x0},
    {.hh = 0x0, .hl = 0x0, .lh = 0x0, .ll = 0x0, .ex = 0, .sgn = 0x0},
    {.hh = 0x0, .hl = 0x0, .lh = 0x0, .ll = 0x0, .ex = 0, .sgn = 0x0},
    {.hh = 0x0, .hl = 0x0, .lh = 0x0, .ll = 0x0, .ex = 0, .sgn = 0x0},
    {.hh = 0x0, .hl = 0x0, .lh = 0x0, .ll = 0x0, .ex = 0, .sgn = 0x0},
    {.hh = 0x0, .hl = 0x0, .lh = 0x0, .ll = 0x0, .ex = 0, .sgn = 0x0},
    {.hh = 0x0, .hl = 0x0, .lh = 0x0, .ll = 0x0, .ex = 0, .sgn = 0x0},
    {.hh = 0x0, .hl = 0x0, .lh = 0x0, .ll = 0x0, .ex = 0, .sgn = 0x0},
    {.hh = 0x0, .hl = 0x0, .lh = 0x0, .ll = 0x0, .ex = 0, .sgn = 0x0},
    {.hh = 0x0, .hl = 0x0, .lh = 0x0, .ll = 0x0, .ex = 0, .sgn = 0x0},
    {.hh = 0x0, .hl = 0x0, .lh = 0x0, .ll = 0x0, .ex = 0, .sgn = 0x0},
    {.hh = 0x0, .hl = 0x0, .lh = 0x0, .ll = 0x0, .ex = 0, .sgn = 0x0},
    {.hh = 0x0, .hl = 0x0, .lh = 0x0, .ll = 0x0, .ex = 0, .sgn = 0x0},
    {.hh = 0x0, .hl = 0x0, .lh = 0x0, .ll = 0x0, .ex = 0, .sgn = 0x0},
    {.hh = 0x0, .hl = 0x0, .lh = 0x0, .ll = 0x0, .ex = 0, .sgn = 0x0},
    {.hh = 0x0, .hl = 0x0, .lh = 0x0, .ll = 0x0, .ex = 0, .sgn = 0x0},
    {.hh = 0x0, .hl = 0x0, .lh = 0x0, .ll = 0x0, .ex = 0, .sgn = 0x0},
    {.hh = 0x0, .hl = 0x0, .lh = 0x0, .ll = 0x0, .ex = 0, .sgn = 0x0},
    {.hh = 0x0, .hl = 0x0, .lh = 0x0, .ll = 0x0, .ex = 0, .sgn = 0x0},
    {.hh = 0x0, .hl = 0x0, .lh = 0x0, .ll = 0x0, .ex = 0, .sgn = 0x0},
    {.hh = 0x0, .hl = 0x0, .lh = 0x0, .ll = 0x0, .ex = 0, .sgn = 0x0},
    {.hh = 0x0, .hl = 0x0, .lh = 0x0, .ll = 0x0, .ex = 0, .sgn = 0x0},
    {.hh = 0x0, .hl = 0x0, .lh = 0x0, .ll = 0x0, .ex = 0, .sgn = 0x0},
    {.hh = 0x0, .hl = 0x0, .lh = 0x0, .ll = 0x0, .ex = 0, .sgn = 0x0},
    {.hh = 0x0, .hl = 0x0, .lh = 0x0, .ll = 0x0, .ex = 0, .sgn = 0x0},
    {.hh = 0x0, .hl = 0x0, .lh = 0x0, .ll = 0x0, .ex = 0, .sgn = 0x0},
    {.hh = 0xb7f285b778428bfc, .hl = 0x71bd800bca7a220e, .lh = 0x66fb247932d20f2b, .ll = 0xebab210f09c0c362, .ex = -7, .sgn = 0x1},
    {.hh = 0xb2387a247d8284e3, .hl = 0x57e870fc57e499a4, .lh = 0x636a285aa4f40f4d, .ll = 0x566ce48b7a855936, .ex = -7, .sgn = 0x1},
    {.hh = 0xb2387a247d8284e3, .hl = 0x57e870fc57e499a4, .lh = 0x636a285aa4f40f4d, .ll = 0x566ce48b7a855936, .ex = -7, .sgn = 0x1},
    {.hh = 0xac7e139e29661e76, .hl = 0xb5980cc40038da56, .lh = 0x124ed60116edd69d, .ll = 0x75464e82713eeb61, .ex = -7, .sgn = 0x1},
    {.hh = 0xac7e139e29661e76, .hl = 0xb5980cc40038da56, .lh = 0x124ed60116edd69d, .ll = 0x75464e82713eeb61, .ex = -7, .sgn = 0x1},
    {.hh = 0xa6c352193251e102, .hl = 0x44c310c007b30aa5, .lh = 0x1ebe915ff51652b6, .ll = 0xb3510c10ec789a54, .ex = -7, .sgn = 0x1},
    {.hh = 0xa6c352193251e102, .hl = 0x44c310c007b30aa5, .lh = 0x1ebe915ff51652b6, .ll = 0xb3510c10ec789a54, .ex = -7, .sgn = 0x1},
    {.hh = 0xa108358a4c904614, .hl = 0xdbfbbb13187aa419, .lh = 0x39951be9b663b6d6, .ll = 0x83f85d146176e716, .ex = -7, .sgn = 0x1},
    {.hh = 0xa108358a4c904614, .hl = 0xdbfbbb13187aa419, .lh = 0x39951be9b663b6d6, .ll = 0x83f85d146176e716, .ex = -7, .sgn = 0x1},
    {.hh = 0x9b4cbde62a5132e2, .hl = 0x669d1d0662ca1ff6, .lh = 0x5cdd3405cd1f6a0a, .ll = 0x1fb503d4e23c8b1e, .ex = -7, .sgn = 0x1},
    {.hh = 0x9b4cbde62a5132e2, .hl = 0x669d1d0662ca1ff6, .lh = 0x5cdd3405cd1f6a0a, .ll = 0x1fb503d4e23c8b1e, .ex = -7, .sgn = 0x1},
    {.hh = 0x9590eb217ba9727c, .hl = 0x604c63eb35c13aee, .lh = 0xa8db3c930bf84b62, .ll = 0x6b669dbbcc034bcd, .ex = -7, .sgn = 0x1},
    {.hh = 0x9590eb217ba9727c, .hl = 0x604c63eb35c13aee, .lh = 0xa8db3c930bf84b62, .ll = 0x6b669dbbcc034bcd, .ex = -7, .sgn = 0x1},
    {.hh = 0x8fd4bd30ee922fe0, .hl = 0xc457fc2daaa8520c, .lh = 0xff24b543efd19790, .ll = 0x123a1c21d1f4880a, .ex = -7, .sgn = 0x1},
    {.hh = 0x8fd4bd30ee922fe0, .hl = 0xc457fc2daaa8520c, .lh = 0xff24b543efd19790, .ll = 0x123a1c21d1f4880a, .ex = -7, .sgn = 0x1},
    {.hh = 0x8a1834092ee86fdf, .hl = 0x6177b8e871103a55, .lh = 0xf9d8117f0decd0b7, .ll = 0xb53f291134c8ed97, .ex = -7, .sgn = 0x1},
    {.hh = 0x8a1834092ee86fdf, .hl = 0x6177b8e871103a55, .lh = 0xf9d8117f0decd0b7, .ll = 0xb53f291134c8ed97, .ex = -7, .sgn = 0x1},
    {.hh = 0x845b4f9ee66c8ad5, .hl = 0x826a6d91778376ef, .lh = 0xad22810102c2d786, .ll = 0xc63cde57a4952c15, .ex = -7, .sgn = 0x1},
    {.hh = 0x845b4f9ee66c8ad5, .hl = 0x826a6d91778376ef, .lh = 0xad22810102c2d786, .ll = 0xc63cde57a4952c15, .ex = -7, .sgn = 0x1},
    {.hh = 0xfd3c1fcd79834c7f, .hl = 0xb7cd4e8a6759dd18, .lh = 0x2b38fbde45913eba, .ll = 0xf83efa3b888eddea, .ex = -8, .sgn = 0x1},
    {.hh = 0xfd3c1fcd79834c7f, .hl = 0xb7cd4e8a6759dd18, .lh = 0x2b38fbde45913eba, .ll = 0xf83efa3b888eddea, .ex = -8, .sgn = 0x1},
    {.hh = 0xf1c0e9aaaeda5c45, .hl = 0x609adf919c095106, .lh = 0x30f8e22370cca02, .ll = 0xac9dac562c5d78eb, .ex = -8, .sgn = 0x1},
    {.hh = 0xf1c0e9aaaeda5c45, .hl = 0x609adf919c095106, .lh = 0x30f8e22370cca02, .ll = 0xac9dac562c5d78eb, .ex = -8, .sgn = 0x1},
    {.hh = 0xe644fcbeb3ac9c90, .hl = 0x330e7b211e535367, .lh = 0xa3eb3dd356f3d057, .ll = 0xb40152fe8f73d339, .ex = -8, .sgn = 0x1},
    {.hh = 0xe644fcbeb3ac9c90, .hl = 0x330e7b211e535367, .lh = 0xa3eb3dd356f3d057, .ll = 0xb40152fe8f73d339, .ex = -8, .sgn = 0x1},
    {.hh = 0xdac858f2ca8ad6a8, .hl = 0xd2d8d3db7ba4fdea, .lh = 0x1306ae0cb59b7c, .ll = 0x85a85eeee42a8d6e, .ex = -8, .sgn = 0x1},
    {.hh = 0xdac858f2ca8ad6a8, .hl = 0xd2d8d3db7ba4fdea, .lh = 0x1306ae0cb59b7c, .ll = 0x85a85eeee42a8d6e, .ex = -8, .sgn = 0x1},
    {.hh = 0xcf4afe3031c73761, .hl = 0x222771f780842123, .lh = 0x9b4a3499f7c927ae, .ll = 0xe9c201fa0623d166, .ex = -8, .sgn = 0x1},
    {.hh = 0xcf4afe3031c73761, .hl = 0x222771f780842123, .lh = 0x9b4a3499f7c927ae, .ll = 0xe9c201fa0623d166, .ex = -8, .sgn = 0x1},
    {.hh = 0xc3ccec6023744094, .hl = 0xfeb55bebcdb9b189, .lh = 0xaaf83f8e06b618da, .ll = 0xf5fe1eed75dec965, .ex = -8, .sgn = 0x1},
    {.hh = 0xc3ccec6023744094, .hl = 0xfeb55bebcdb9b189, .lh = 0xaaf83f8e06b618da, .ll = 0xf5fe1eed75dec965, .ex = -8, .sgn = 0x1},
    {.hh = 0xb84e236bd563ba56, .hl = 0xcde92497c21d6f04, .lh = 0x4ff1f978abf5506e, .ll = 0xaa4a93db4258ac62, .ex = -8, .sgn = 0x1},
    {.hh = 0xb84e236bd563ba56, .hl = 0xcde92497c21d6f04, .lh = 0x4ff1f978abf5506e, .ll = 0xaa4a93db4258ac62, .ex = -8, .sgn = 0x1},
    {.hh = 0xaccea33c7925a3c7, .hl = 0xb88c7c21367036fe, .lh = 0x51bcc70bebdc51ac, .ll = 0x6ccaa3c73a26d80f, .ex = -8, .sgn = 0x1},
    {.hh = 0xaccea33c7925a3c7, .hl = 0xb88c7c21367036fe, .lh = 0x51bcc70bebdc51ac, .ll = 0x6ccaa3c73a26d80f, .ex = -8, .sgn = 0x1},
    {.hh = 0xa14e6bbb3c07239b, .hl = 0x769baa78775f128c, .lh = 0x4c6855010eb293b, .ll = 0x4403fb4b7583309f, .ex = -8, .sgn = 0x1},
    {.hh = 0xa14e6bbb3c07239b, .hl = 0x769baa78775f128c, .lh = 0x4c6855010eb293b, .ll = 0x4403fb4b7583309f, .ex = -8, .sgn = 0x1},
    {.hh = 0x95cd7cd147117847, .hl = 0x8b9d9d5879701c9a, .lh = 0x73cacda7f09b3b64, .ll = 0x1db3dfaeabc23522, .ex = -8, .sgn = 0x1},
    {.hh = 0x95cd7cd147117847, .hl = 0x8b9d9d5879701c9a, .lh = 0x73cacda7f09b3b64, .ll = 0x1db3dfaeabc23522, .ex = -8, .sgn = 0x1},
    {.hh = 0x8a4bd667bf08e7dd, .hl = 0xd3e76fa49e34c62f, .lh = 0x15f98c516d93c09e, .ll = 0x2ebb0e404d39c0b8, .ex = -8, .sgn = 0x1},
    {.hh = 0x8a4bd667bf08e7dd, .hl = 0xd3e76fa49e34c62f, .lh = 0x15f98c516d93c09e, .ll = 0x2ebb0e404d39c0b8, .ex = -8, .sgn = 0x1},
    {.hh = 0xfd92f0cf88d75f24, .hl = 0x86410a676480a5a6, .lh = 0xfee24bf355f62327, .ll = 0xbe2995707812c6f6, .ex = -9, .sgn = 0x1},
    {.hh = 0xfd92f0cf88d75f24, .hl = 0x86410a676480a5a6, .lh = 0xfee24bf355f62327, .ll = 0xbe2995707812c6f6, .ex = -9, .sgn = 0x1},
    {.hh = 0xe68cc574e6e1e5d7, .hl = 0x689d08ca6c7c3eb1, .lh = 0x349279c75256d20b, .ll = 0xb8057e2cd419f1fc, .ex = -9, .sgn = 0x1},
    {.hh = 0xe68cc574e6e1e5d7, .hl = 0x689d08ca6c7c3eb1, .lh = 0x349279c75256d20b, .ll = 0xb8057e2cd419f1fc, .ex = -9, .sgn = 0x1},
    {.hh = 0xcf852a91c80f553f, .hl = 0x57453c8d5dc64ce0, .lh = 0xf788997112090a4a, .ll = 0x4ebbfb4570a3329e, .ex = -9, .sgn = 0x1},
    {.hh = 0xcf852a91c80f553f, .hl = 0x57453c8d5dc64ce0, .lh = 0xf788997112090a4a, .ll = 0x4ebbfb4570a3329e, .ex = -9, .sgn = 0x1},
    {.hh = 0xb87c1ff853ab2631, .hl = 0xd4676d1d81755808, .lh = 0xc691a0905f1e2c27, .ll = 0x9d2204e831254d6e, .ex = -9, .sgn = 0x1},
    {.hh = 0xb87c1ff853ab2631, .hl = 0xd4676d1d81755808, .lh = 0xc691a0905f1e2c27, .ll = 0x9d2204e831254d6e, .ex = -9, .sgn = 0x1},
    {.hh = 0xa171a57aa86c3551, .hl = 0x67862c8ec9dcd60d, .lh = 0x50c1583992a610d4, .ll = 0xcdc386af31a4e7ca, .ex = -9, .sgn = 0x1},
    {.hh = 0xa171a57aa86c3551, .hl = 0x67862c8ec9dcd60d, .lh = 0x50c1583992a610d4, .ll = 0xcdc386af31a4e7ca, .ex = -9, .sgn = 0x1},
    {.hh = 0x8a65baeadc729ec5, .hl = 0x4d36cd474f65a317, .lh = 0x570a4455dd16cf44, .ll = 0xf530b2a948060f3f, .ex = -9, .sgn = 0x1},
    {.hh = 0x8a65baeadc729ec5, .hl = 0x4d36cd474f65a317, .lh = 0x570a4455dd16cf44, .ll = 0xf530b2a948060f3f, .ex = -9, .sgn = 0x1},
    {.hh = 0xe6b0c035fa8b328c, .hl = 0x162ef4b0e838c363, .lh = 0x28150da572dd7ffe, .ll = 0x1d583fe495f2d584, .ex = -10, .sgn = 0x1},
    {.hh = 0xe6b0c035fa8b328c, .hl = 0x162ef4b0e838c363, .lh = 0x28150da572dd7ffe, .ll = 0x1d583fe495f2d584, .ex = -10, .sgn = 0x1},
    {.hh = 0xb89329ba1fa2a0fd, .hl = 0x4fca1c931bd6e6d5, .lh = 0xd769e9cbf9afec63, .ll = 0x19073808051a937c, .ex = -10, .sgn = 0x1},
    {.hh = 0xb89329ba1fa2a0fd, .hl = 0x4fca1c931bd6e6d5, .lh = 0xd769e9cbf9afec63, .ll = 0x19073808051a937c, .ex = -10, .sgn = 0x1},
    {.hh = 0x8a72b20620c97d84, .hl = 0x8ef87f1a11cdb726, .lh = 0xb79c7bae6fd7c1be, .ll = 0x19131acd5bca3a62, .ex = -10, .sgn = 0x1},
    {.hh = 0x8a72b20620c97d84, .hl = 0x8ef87f1a11cdb726, .lh = 0xb79c7bae6fd7c1be, .ll = 0x19131acd5bca3a62, .ex = -10, .sgn = 0x1},
    {.hh = 0xb89eb17bcabe1857, .hl = 0xa9d69d37bc0a5bac, .lh = 0xf4107fa9468ea43, .ll = 0x5da5fc4298448794, .ex = -11, .sgn = 0x1},
    {.hh = 0xb89eb17bcabe1857, .hl = 0xa9d69d37bc0a5bac, .lh = 0xf4107fa9468ea43, .ll = 0x5da5fc4298448794, .ex = -11, .sgn = 0x1},
    {.hh = 0xb8a476150dfe4470, .hl = 0x878035864d84b319, .lh = 0xdbd937b5fab3906, .ll = 0x7b827a4de8bde1b7, .ex = -12, .sgn = 0x1},
    {.hh = 0x0, .hl = 0x0, .lh = 0x0, .ll = 0x0, .ex = 0, .sgn = 0x0},
    {.hh = 0x0, .hl = 0x0, .lh = 0x0, .ll = 0x0, .ex = 0, .sgn = 0x0},
};

/* t0[i] is a double-double approximation of 2^(i/2^20)
   with absolute error less than 2^-107 */
_Alignas(16) static const double t0[32][2] = {
   {0x1p+0, 0x0p+0},
   {0x1.00000b1721bdp+0, -0x1.b31303b78afcbp-55},
   {0x1.0000162e43f5p+0, -0x1.f3be7c7f49f19p-54},
   {0x1.0000214566a7fp+0, 0x1.656c292b5fbf1p-55},
   {0x1.00002c5c89d5fp+0, -0x1.c9ad941ba99ffp-55},
   {0x1.00003773ad7eep+0, 0x1.46efec33f13d8p-54},
   {0x1.0000428ad1a2ep+0, -0x1.914187f0dd6eep-55},
   {0x1.00004da1f641dp+0, 0x1.db985450c12b8p-55},
   {0x1.000058b91b5bdp+0, -0x1.9474449f85921p-54},
   {0x1.000063d040f0cp+0, -0x1.38342ddcff839p-56},
   {0x1.00006ee76700bp+0, 0x1.84adb511b1f9bp-55},
   {0x1.000079fe8d8bap+0, 0x1.9e0c725732612p-54},
   {0x1.00008515b491ap+0, -0x1.b9973f0700531p-54},
   {0x1.0000902cdc129p+0, -0x1.433f347dc5b72p-54},
   {0x1.00009b44040e8p+0, -0x1.fb2cd1d4bcb48p-55},
   {0x1.0000a65b2c857p+0, -0x1.ce8fae3689858p-55},
   {0x1.0000b17255776p+0, -0x1.fdfcf3a05ada9p-55},
   {0x1.0000bc897ee45p+0, -0x1.43654bba06cc7p-54},
   {0x1.0000c7a0a8cc4p+0, -0x1.b327477af948p-54},
   {0x1.0000d2b7d32f2p+0, 0x1.b310985998c3ep-54},
   {0x1.0000ddcefe0d1p+0, 0x1.e12eb27e260dbp-55},
   {0x1.0000e8e62966p+0, 0x1.b0802fe7cf65ap-60},
   {0x1.0000f3fd5539fp+0, -0x1.091a6b8bd2cep-54},
   {0x1.0000ff148188dp+0, 0x1.c2571a0472bcp-54},
   {0x1.00010a2bae52cp+0, 0x1.a9ae5c9baf091p-56},
   {0x1.00011542db97bp+0, -0x1.0f87ee5f25c56p-54},
   {0x1.0001205a09579p+0, 0x1.55d18f46462bp-54},
   {0x1.00012b7137928p+0, -0x1.90cba8180959p-56},
   {0x1.0001368866486p+0, 0x1.c3bfabad94de8p-54},
   {0x1.0001419f95795p+0, -0x1.880d4cf4cfe93p-57},
   {0x1.00014cb6c5253p+0, 0x1.bede1c249162bp-54},
   {0x1.000157cdf54c2p+0, -0x1.ad2ff3ac0a8b3p-56},
};

/* t1[i] is a double-double approximation of 2^(i/2^15)
   with absolute error less than 2^-107 */
_Alignas(16) static const double t1[32][2] = {
   {0x1p+0, 0x0p+0},
   {0x1.000162e525eep+0, 0x1.51d5115f56655p-54},
   {0x1.0002c5cc37da9p+0, 0x1.247426170d232p-54},
   {0x1.000428b535c85p+0, 0x1.fb74d9ea60832p-54},
   {0x1.00058ba01fbap+0, -0x1.a4a4d4cad39fep-54},
   {0x1.0006ee8cf5b22p+0, 0x1.932ef86740288p-55},
   {0x1.0008517bb7b38p+0, -0x1.9bcb5db05e94p-57},
   {0x1.0009b46c65c0bp+0, 0x1.eb71a14c21e8bp-54},
   {0x1.000b175effdc7p+0, 0x1.ae8e38c59c72ap-54},
   {0x1.000c7a5386096p+0, 0x1.9efe59410befap-54},
   {0x1.000ddd49f84a3p+0, 0x1.1b41ae4029256p-56},
   {0x1.000f404256a18p+0, 0x1.87fa20970e17ap-57},
   {0x1.0010a33ca112p+0, -0x1.68ddbffb2ac39p-58},
   {0x1.00120638d79e5p+0, 0x1.fcfcbaad3ac82p-54},
   {0x1.00136936fa493p+0, 0x1.f2be4da91d517p-55},
   {0x1.0014cc3709154p+0, -0x1.257410422c2fdp-55},
   {0x1.00162f3904052p+0, -0x1.7b5d0d58ea8f4p-58},
   {0x1.0017923ceb1b8p+0, 0x1.f5e282a52dbd9p-55},
   {0x1.0018f542be5b1p+0, 0x1.36ad1777e482p-54},
   {0x1.001a584a7dc68p+0, -0x1.a447def06db7ep-55},
   {0x1.001bbb5429606p+0, 0x1.73c902846716ep-54},
   {0x1.001d1e5fc12b8p+0, -0x1.6354c4339b91p-54},
   {0x1.001e816d452a6p+0, 0x1.3da68462bd1e4p-54},
   {0x1.001fe47cb55fdp+0, -0x1.334e0c9692b31p-58},
   {0x1.0021478e11ce6p+0, 0x1.4115cb6b16a8ep-54},
   {0x1.0022aaa15a78dp+0, -0x1.6c81d3063bdb2p-57},
   {0x1.00240db68f61cp+0, -0x1.c65136ca57a55p-54},
   {0x1.002570cdb08bdp+0, -0x1.ded5dcc6c5bd4p-55},
   {0x1.0026d3e6bdf9bp+0, 0x1.e3a2b72b6b281p-55},
   {0x1.00283701b7ae2p+0, -0x1.870119822944dp-54},
   {0x1.00299a1e9dabbp+0, -0x1.bd5a8a6af3c4ep-54},
   {0x1.002afd3d6ff51p+0, -0x1.13c6aeb99597p-54},
};

/* t2[i] is a double-double approximation of 2^(i/2^10)
   with absolute error less than 2^-107 */
_Alignas(16) static const double t2[32][2] = {
   {0x1p+0, 0x0p+0},
   {0x1.002c605e2e8cfp+0, -0x1.d7c96f201bb2fp-55},
   {0x1.0058c86da1c0ap+0, -0x1.5e00e62d6b30dp-56},
   {0x1.0085382faef83p+0, 0x1.da93f90835f75p-56},
   {0x1.00b1afa5abcbfp+0, -0x1.4f6b2a7609f71p-55},
   {0x1.00de2ed0ee0f5p+0, -0x1.406ac4e81a645p-57},
   {0x1.010ab5b2cbd11p+0, 0x1.c1d0660524e08p-54},
   {0x1.0137444c9b5b5p+0, -0x1.2b6aeb6176892p-56},
   {0x1.0163da9fb3335p+0, 0x1.b61299ab8cdb7p-54},
   {0x1.019078ad6a19fp+0, -0x1.008eff5142bf9p-56},
   {0x1.01bd1e77170b4p+0, 0x1.5e7626621eb5bp-56},
   {0x1.01e9cbfe113efp+0, -0x1.c11f5239bf535p-55},
   {0x1.02168143b0281p+0, -0x1.2bf310fc54eb6p-55},
   {0x1.02433e494b755p+0, -0x1.314aa16278aa3p-54},
   {0x1.027003103b10ep+0, -0x1.082ef51b61d7ep-56},
   {0x1.029ccf99d720ap+0, 0x1.64cbba902ca27p-58},
   {0x1.02c9a3e778061p+0, -0x1.19083535b085dp-56},
   {0x1.02f67ffa765e6p+0, -0x1.b8db0e9dbd87ep-55},
   {0x1.032363d42b027p+0, 0x1.fea8d61ed6016p-54},
   {0x1.03504f75ef071p+0, 0x1.bc2ee8e5799acp-54},
   {0x1.037d42e11bbccp+0, 0x1.56811eeade11ap-57},
   {0x1.03aa3e170aafep+0, -0x1.f1a93c1b824d3p-54},
   {0x1.03d7411915a8ap+0, 0x1.b7c00e7b751dap-54},
   {0x1.04044be896ab6p+0, 0x1.9dc3add8f9c02p-54},
   {0x1.04315e86e7f85p+0, -0x1.0a31c1977c96ep-54},
   {0x1.045e78f5640b9p+0, 0x1.35bc86af4ee9ap-56},
   {0x1.048b9b35659d8p+0, 0x1.21cd53d5e8b66p-57},
   {0x1.04b8c54847a28p+0, -0x1.e7992580447bp-56},
   {0x1.04e5f72f654b1p+0, 0x1.4c3793aa0d08dp-55},
   {0x1.051330ec1a03fp+0, 0x1.79a8be239ca45p-54},
   {0x1.0540727fc1762p+0, -0x1.abcae24b819dfp-54},
   {0x1.056dbbebb786bp+0, 0x1.06c87433776c9p-55},
};


/* t3[i] is a double-double approximation of 2^(i/2^5)
   with absolute error less than 2^-107 */
_Alignas(16)
static const double t3[32][2] = {
   {0x1p+0, 0x0p+0},
   {0x1.059b0d3158574p+0, 0x1.d73e2a475b465p-55},
   {0x1.0b5586cf9890fp+0, 0x1.8a62e4adc610bp-54},
   {0x1.11301d0125b51p+0, -0x1.6c51039449b3ap-54},
   {0x1.172b83c7d517bp+0, -0x1.19041b9d78a76p-55},
   {0x1.1d4873168b9aap+0, 0x1.e016e00a2643cp-54},
   {0x1.2387a6e756238p+0, 0x1.9b07eb6c70573p-54},
   {0x1.29e9df51fdee1p+0, 0x1.612e8afad1255p-55},
   {0x1.306fe0a31b715p+0, 0x1.6f46ad23182e4p-55},
   {0x1.371a7373aa9cbp+0, -0x1.63aeabf42eae2p-54},
   {0x1.3dea64c123422p+0, 0x1.ada0911f09ebcp-55},
   {0x1.44e086061892dp+0, 0x1.89b7a04ef80dp-59},
   {0x1.4bfdad5362a27p+0, 0x1.d4397afec42e2p-56},
   {0x1.5342b569d4f82p+0, -0x1.07abe1db13cadp-55},
   {0x1.5ab07dd485429p+0, 0x1.6324c054647adp-54},
   {0x1.6247eb03a5585p+0, -0x1.383c17e40b497p-54},
   {0x1.6a09e667f3bcdp+0, -0x1.bdd3413b26456p-54},
   {0x1.71f75e8ec5f74p+0, -0x1.16e4786887a99p-55},
   {0x1.7a11473eb0187p+0, -0x1.41577ee04992fp-55},
   {0x1.82589994cce13p+0, -0x1.d4c1dd41532d8p-54},
   {0x1.8ace5422aa0dbp+0, 0x1.6e9f156864b27p-54},
   {0x1.93737b0cdc5e5p+0, -0x1.75fc781b57ebcp-57},
   {0x1.9c49182a3f09p+0, 0x1.c7c46b071f2bep-56},
   {0x1.a5503b23e255dp+0, -0x1.d2f6edb8d41e1p-54},
   {0x1.ae89f995ad3adp+0, 0x1.7a1cd345dcc81p-54},
   {0x1.b7f76f2fb5e47p+0, -0x1.5584f7e54ac3bp-56},
   {0x1.c199bdd85529cp+0, 0x1.11065895048ddp-55},
   {0x1.cb720dcef9069p+0, 0x1.503cbd1e949dbp-56},
   {0x1.d5818dcfba487p+0, 0x1.2ed02d75b3707p-55},
   {0x1.dfc97337b9b5fp+0, -0x1.1a5cd4f184b5cp-54},
   {0x1.ea4afa2a490dap+0, -0x1.e9c23179c2893p-54},
   {0x1.f50765b6e454p+0, 0x1.9d3e12dd8a18bp-54},
};

/* For 0 <= i < 32, let (h, l) denote t0_corr[i]. Then 
   2^(i/2^20)*2^(h/2^-167)*2^(l/2^(-167-126))*2^eps = t0[i]
	 for some eps satisfying |eps| <= 2^-294.064,
         and where l denotes lh*2^64 + ll.
	 Furthermore :
	   - h may be signed, l is not
	   - |h| < 2^61
	   - |l| < 2^126
  Table generated by corr_tk(k=0) from powl.sage.
*/
static const corr_t t0_corr[32] = {
   {.h=0L,.lh=0UL,.ll=0UL},
   {.h=774929132767867848L,.lh=1877417623945036096UL,.ll=2946102060019946640UL},
   {.h=1152983087779699084L,.lh=2854112676240020970UL,.ll=3486792221048696928UL},
   {.h=411479515052328607L,.lh=3461372359994950289UL,.ll=12152312648290311971UL},
   {.h=430489315293535351L,.lh=1304363903236854336UL,.ll=14851609239966531299UL},
   {.h=1567191953159852675L,.lh=4143902603473940408UL,.ll=16353543234576344964UL},
   {.h=193532155547004167L,.lh=2953378289009346596UL,.ll=673337807639235256UL},
   {.h=-459684616915234986L,.lh=292091744314364626UL,.ll=5385086044652010622UL},
   {.h=-1081731661819227306L,.lh=4167479800343936943UL,.ll=12635046618239985139UL},
   {.h=403814243698214526L,.lh=278569040164944092UL,.ll=17660525355986562313UL},
   {.h=555070806723885411L,.lh=2248257256854233118UL,.ll=17663579771879729817UL},
   {.h=-407470032062119841L,.lh=1857294676771971437UL,.ll=13195107672451562259UL},
   {.h=-1063427881900495373L,.lh=2963675100164639311UL,.ll=3462274273898311817UL},
   {.h=-423382515246486031L,.lh=329378069527744126UL,.ll=2537249758277897189UL},
   {.h=440261468897549132L,.lh=1558056522350020454UL,.ll=6310835967003904796UL},
   {.h=-742659601358045413L,.lh=4515058680046460125UL,.ll=13918117927443431125UL},
   {.h=77157518026342326L,.lh=3021537648705645327UL,.ll=17407997819184859975UL},
   {.h=826111294894068145L,.lh=1828098466315393397UL,.ll=8834480979744875422UL},
   {.h=-838411632912129652L,.lh=3155534129043983369UL,.ll=18154696080117488242UL},
   {.h=1652397245814591285L,.lh=286192135387568950UL,.ll=15186312101125587588UL},
   {.h=-306699853796005661L,.lh=2119012223438506862UL,.ll=1231966673515674499UL},
   {.h=-3644671385737491L,.lh=1953199599587706369UL,.ll=13095817821484027179UL},
   {.h=401458940920939123L,.lh=603430287886083932UL,.ll=7452633664463290281UL},
   {.h=-735396084717356438L,.lh=4324740189561577495UL,.ll=16216502057870408483UL},
   {.h=272037800551873727L,.lh=2355714735010911589UL,.ll=2910903783960484167UL},
   {.h=-729907917177577149L,.lh=1287765903212814545UL,.ll=8344584172273110709UL},
   {.h=410449045200200515L,.lh=206050814502223634UL,.ll=15736071637589171320UL},
   {.h=381051676181877819L,.lh=3076490124979304507UL,.ll=3520072396569624453UL},
   {.h=-1582054453251485069L,.lh=524480126911522609UL,.ll=8296779138412573297UL},
   {.h=79750016149675063L,.lh=4242381716696743401UL,.ll=282803620515757307UL},
   {.h=-600563029754532991L,.lh=1930698367164787072UL,.ll=3628592756075222996UL},
   {.h=-292580942853584671L,.lh=332452509863185593UL,.ll=14405767013311328059UL},
};


/* For 0 <= i < 32, let (h, l) denote t1_corr[i]. Then 
   2^(i/2^15)*2^(h/2^-167)*2^(l/2^(-167-126))*2^eps = t2[i]
	 for some eps satisfying |eps| <= 2^-294.003.
	 Furthermore :
	   - h may be signed, l is not
	   - |h| < 2^61
	   - |l| < 2^126
  Table generated by corr_tk(k=1) from powl.sage.
*/
static const corr_t t1_corr[32] = {
   {.h=0L,.lh=0UL,.ll=0UL},
   {.h=1188953751062791134L,.lh=2086390938573950067UL,.ll=4826928784532323317UL},
   {.h=1200389652625304084L,.lh=2685434046295363506UL,.ll=15420523437626342UL},
   {.h=-262518421427856831L,.lh=370061188545645089UL,.ll=4789785131903739441UL},
   {.h=-908785239346841084L,.lh=569295103404623815UL,.ll=9269529158181861301UL},
   {.h=-269435382309264733L,.lh=376243117343056489UL,.ll=1550763655202437534UL},
   {.h=21766436124569359L,.lh=3424377584541956478UL,.ll=17671383104086764196UL},
   {.h=-435358558109268233L,.lh=3022457375774224007UL,.ll=7794973847800415989UL},
   {.h=-1018110162167119661L,.lh=1507442351835637750UL,.ll=14689795751289072121UL},
   {.h=-1023552101470246661L,.lh=3916829430730806602UL,.ll=6951684205434248043UL},
   {.h=-191443270819959372L,.lh=80570590733043138UL,.ll=17190356786238666267UL},
   {.h=-150406130943380018L,.lh=2673858577758106594UL,.ll=14119339113821199808UL},
   {.h=-23466250249022719L,.lh=2853918773925218492UL,.ll=17696018260859624766UL},
   {.h=-1047390836450858784L,.lh=3865978597360116630UL,.ll=15500526870105070121UL},
   {.h=692913748158290335L,.lh=48225857049655798UL,.ll=14840543958109069277UL},
   {.h=-561814798314761789L,.lh=3010485976946184646UL,.ll=8819873022417789679UL},
   {.h=-98619637063377440L,.lh=4441957806117115117UL,.ll=3120479350716796085UL},
   {.h=-249870542080734769L,.lh=3398325503434046707UL,.ll=17551487887720366469UL},
   {.h=634295850579542383L,.lh=3308853313819620192UL,.ll=7993625654491051464UL},
   {.h=65417985188852312L,.lh=483096963561942340UL,.ll=12962680571670057447UL},
   {.h=-614426543014302436L,.lh=2959377363482573051UL,.ll=8593076768362713803UL},
   {.h=-120634774829195467L,.lh=2952588742932461954UL,.ll=4601605825241518030UL},
   {.h=650954664248522803L,.lh=2812558602123452894UL,.ll=11640820773396380270UL},
   {.h=40401537892522165L,.lh=1390447014275346772UL,.ll=9517543706821362178UL},
   {.h=-140444997293478671L,.lh=3223338636967069385UL,.ll=6705968974674712053UL},
   {.h=90807363200474862L,.lh=3426000142274961548UL,.ll=4684375371610364606UL},
   {.h=-45104394707644236L,.lh=1113926508569668020UL,.ll=5643244807667921623UL},
   {.h=56086847392660778L,.lh=440343167786255728UL,.ll=17726412119615946138UL},
   {.h=313968424617421027L,.lh=1388509411243765078UL,.ll=6480652115689029191UL},
   {.h=859153589799647659L,.lh=4058183983073243992UL,.ll=13755433644881233825UL},
   {.h=1433175892871988186L,.lh=481220814130565949UL,.ll=10568594051040564370UL},
   {.h=1274706280519865680L,.lh=2043227249338976831UL,.ll=2220543334117998846UL},
};

/* For 0 <= i < 32, let (h, l) denote t2_corr[i]. Then 
   2^(i/2^10)*2^(h/2^-167)*2^(l/2^(-167-126))*2^eps = t2[i]
	 for some eps satisfying |eps| <= 2^-294.051.
	 Furthermore :
	   - h may be signed, l is not
	   - |h| < 2^61
	   - |l| < 2^126
  Table generated by corr_tk(k=2) from powl.sage.
*/
static const corr_t t2_corr[32] = {
   {.h=0L,.lh=0UL,.ll=0UL},
   {.h=-188307883512772844L,.lh=2410844611908356161UL,.ll=3259474191313504333UL},
   {.h=30899402473242025L,.lh=99506931431156031UL,.ll=9115491649412450447UL},
   {.h=-183084639610094399L,.lh=316406921196805977UL,.ll=15807824707186179010UL},
   {.h=177126679395176436L,.lh=2493466133869669288UL,.ll=14014745001407256872UL},
   {.h=93711878749387220L,.lh=814518508474159762UL,.ll=17118407983521651530UL},
   {.h=-1516806312206829980L,.lh=1055629578944731337UL,.ll=3972137515475016116UL},
   {.h=-24941479673346993L,.lh=1662386239127867813UL,.ll=8836118942562781912UL},
   {.h=-722608765708183549L,.lh=3992200137705468115UL,.ll=3070148369932205617UL},
   {.h=280612129753096217L,.lh=915955601849647438UL,.ll=7336019846715816097UL},
   {.h=258264642599563278L,.lh=3739827987035027307UL,.ll=3070153845635869456UL},
   {.h=575970606347324151L,.lh=3539738491708450130UL,.ll=3985292187679621297UL},
   {.h=-659504653164687154L,.lh=1634604970579418053UL,.ll=14865027500063008369UL},
   {.h=366989966692612624L,.lh=2276009490437258263UL,.ll=12698362779344005483UL},
   {.h=-316381934404329247L,.lh=1990354443775676678UL,.ll=3990420129654373517UL},
   {.h=-69850577703358217L,.lh=606211083069833436UL,.ll=10836831226689198039UL},
   {.h=321786155128740907L,.lh=619734742249425359UL,.ll=2614880292394325790UL},
   {.h=695201931622403780L,.lh=2367943190397363748UL,.ll=16157159210176547445UL},
   {.h=-1059086935495191657L,.lh=4391608553143888379UL,.ll=10428413797829054458UL},
   {.h=-918375444553218847L,.lh=3692879288808004408UL,.ll=7442162413167536634UL},
   {.h=-110202101002749059L,.lh=4176510134762466156UL,.ll=13200978654128253757UL},
   {.h=-676287131838980318L,.lh=86315641924652997UL,.ll=6305117425079219000UL},
   {.h=1596739555728066819L,.lh=3256238251107249571UL,.ll=14488885967158892366UL},
   {.h=-370995194150133280L,.lh=13028588970736891UL,.ll=11997346769447419934UL},
   {.h=80144785045674986L,.lh=2994342203253780641UL,.ll=7669120248247274852UL},
   {.h=-126712138571263884L,.lh=2875272507626330788UL,.ll=2300033439168195317UL},
   {.h=-14589956054825194L,.lh=1936388569361743967UL,.ll=1720456326551757696UL},
   {.h=-142616120879745389L,.lh=1375004853685207001UL,.ll=5270073902699376551UL},
   {.h=806088904884413571L,.lh=2109369290898968069UL,.ll=13975569175908520449UL},
   {.h=-1590384436753558841L,.lh=301871397133273971UL,.ll=2237600872356608982UL},
   {.h=-509185878654638947L,.lh=2394733518962377818UL,.ll=1221069478597070359UL},
   {.h=448804372824836685L,.lh=2881204071100539228UL,.ll=1878524264513842465UL},
};


/* For 0 <= i < 32, let (h, l) denote t2_corr[i]. Then 
   2^(i/2^10)*2^(h/2^-167)*2^(l/2^(-167-126))*2^eps = t2[i]
	 for some eps satisfying |eps| <= 2^-294.057.
	 Furthermore :
	   - h may be signed, l is not
	   - |h| < 2^61
	   - |l| < 2^126
  Table generated by corr_tk(k=3) from powl.sage.
*/
static const corr_t t3_corr[32] = {
   {.h=0L,.lh=0UL,.ll=0UL},
   {.h=-208226367701282158L,.lh=1881570934240644082UL,.ll=15338819650725614653UL},
   {.h=1119274665622562301L,.lh=2517131680502636761UL,.ll=9378771030972421185UL},
   {.h=-629168700988933009L,.lh=739493678094436468UL,.ll=7285546516964456887UL},
   {.h=-499197934480165415L,.lh=2698125982893885588UL,.ll=12015933767608214597UL},
   {.h=-357393333899758965L,.lh=2801229783848713977UL,.ll=2674411754993612838UL},
   {.h=475748881828669037L,.lh=2409886748982518349UL,.ll=2106396925452827155UL},
   {.h=-166913298225837269L,.lh=2340580690462637113UL,.ll=13729683591743264762UL},
   {.h=-259165434006226852L,.lh=1601131655016755876UL,.ll=3107479007111675603UL},
   {.h=-1047620489869692439L,.lh=3872804356043530363UL,.ll=10942914093977802813UL},
   {.h=502979394423616205L,.lh=851717704527474417UL,.ll=6995383462306494888UL},
   {.h=10670118888958124L,.lh=2613337229448379932UL,.ll=16921086789830932861UL},
   {.h=-35104003081013887L,.lh=2438831117652664538UL,.ll=18434283172698894815UL},
   {.h=-155187790775441390L,.lh=3792271529799350494UL,.ll=12066909573461054687UL},
   {.h=446556360731515709L,.lh=2629004368722206680UL,.ll=5407469421139352287UL},
   {.h=-102570831938393666L,.lh=144654838951527966UL,.ll=8494382579545102407UL},
   {.h=-789823721317163766L,.lh=2941246313035683936UL,.ll=17617563917519369003UL},
   {.h=331110760208688850L,.lh=2014295525521940319UL,.ll=240982654137616228UL},
   {.h=22141420441671789L,.lh=3029582134116773332UL,.ll=11451783793520962921UL},
   {.h=-36516181296444371L,.lh=1235474536028442665UL,.ll=10180433785616392820UL},
   {.h=160299981716298225L,.lh=702717725859271960UL,.ll=18364202384433195573UL},
   {.h=-93145740376935802L,.lh=2231567242581460491UL,.ll=5607261700634016052UL},
   {.h=-179259222679467842L,.lh=2856992477232342896UL,.ll=611472291143024564UL},
   {.h=110503065377981329L,.lh=3201046376444073516UL,.ll=961354040646285774UL},
   {.h=-818994019092100952L,.lh=1330825122818542156UL,.ll=15419063310223941516UL},
   {.h=-100749619560038133L,.lh=3302455342723020156UL,.ll=17662084632639004973UL},
   {.h=-189552648221788760L,.lh=2584278066041020632UL,.ll=9391744468253842460UL},
   {.h=-213804761512417499L,.lh=3118190346710438594UL,.ll=16041918579043621716UL},
   {.h=94550045031401536L,.lh=4641018140424848UL,.ll=1501664960935400521UL},
   {.h=-761190116124262793L,.lh=505424527786331920UL,.ll=14732173486610909752UL},
   {.h=430896508243880519L,.lh=3478349114999142212UL,.ll=16444891105338311032UL},
   {.h=132833613503630502L,.lh=1258898424917789488UL,.ll=7728941749525249307UL},
};
