#ifndef FAB_H_INCLUDED
#define FAB_H_INCLUDED

/*
	Interpolated Fabius function, 128 segments, global error < 1.7e-23 
	fab(x) fabius function with convention fab(x) = 0, x < 0 and fab(x) = 1, x > 0
	fabd(x) fabius first derivative
	fabdd(x) fabius second derivative
	fabi(x) fabius first integral
	fabii(x) fabius second integral
*/

// SPDX-License-Identifier: MIT
// Copyright (c) 2026 Zymplectic

inline long double fab_eval(long double x) { // 0 <= x <= 0.5L	
	const long double u[] = {0xd.0a779ef3a5434430p-73L,0xa.b945bf6ec96bb940p-66L,0xd.00d00d00d00d00d0p-63L,0x8.cb85916b4059c000p-60L,0x8.4ebdcf6b2f9687a0p-58L,0xb.efb572c9994e5130p-57L,0xd.a1dc0333dfce1b40p-56L,0xc.b38e4ce6642117e0p-55L,0x9.cfaf30d40c802440p-54L,0xb.e75f5ad36801c8d0p-57L,0xb.a32bf9dc0f8814f0p-53L,0xc.f19bd7793d651780p-50L,0x9.63bc12092fbe9950p-47L,0x9.4ca33d766cd01090p-45L,0xc.b35065aa94552bf0p-44L,0x8.77eb0ce9b2295b80p-51L,0xa.26bc0377b0352b80p-47L,0xe.2ca8ba6d4f9a30a0p-44L,0xc.81d3af19c59d98c0p-41L,0xe.140f44f205807bb0p-39L,0xb.50188fc1dfac33a0p-51L,0xc.ce4ac37b25fff690p-46L,0xe.80bc32663b3fac60p-42L,0x9.ce3f3d555f56c050p-38L,0x8.207cf0c4f315e9a0p-35L,0xa.a9ebaf537e1115c0p-45L,0x8.f58461eee4254070p-40L,0x8.87b28f7b3fde75e0p-36L,0x9.a491034dae8c96e0p-33L,0xe.876210332503c630p-45L,0x8.716545d36a7cd180p-39L,0xa.a0ef36013a18f1f0p-35L,0xf.86d2c9348eb5aba0p-32L,0x8.54c2192aa392f430p-44L,0xd.5eb911675e8513f0p-39L,0xa.bda7034c771f6f80p-34L,0x9.c1f9e9b35dc6c320p-30L,0x8.88290adcf23bbe10p-44L,0x9.5558bdcc56224d50p-38L,0x9.5f68190bd9c2eb30p-33L,0xa.5471cc04495f8680p-29L,0xb.fffc9788ff330810p-38L,0xe.b4bd6e612f184080p-33L,0x9.a3fffd8c1433cb00p-28L,0xe.a5f8cca1a612cb60p-38L,0xa.af69c0d31dc7dbe0p-32L,0x8.2edd3490b0b8eec0p-27L,0x8.8e515935d00b7650p-37L,0xe.a9733c157c987390p-32L,0xc.eae5db7d77fc19c0p-27L,0x9.8bfa1e6cce2602a0p-37L,0x9.9992e9d12f544900p-31L,0x9.a04516dcf2dbca60p-26L,0xa.36a4c91778d0ad40p-37L,0xc.139c7e7aaabead80p-31L,0xd.af7dfa6b2bbf58a0p-26L,0xa.8e515935d00b7650p-37L,0xe.adcb1f96711c1210p-31L,0x9.598ecc34b3545bc0p-25L,0xa.a851bba6285ebb00p-37L,0x8.aabd43f125978450p-30L,0xc.59c58607ba671f40p-25L,0xa.aaa8f66f2a442eb0p-37L,0xa.00000659c7267330p-30L,0xf.d9c71c2349a2eb20p-25L,0xb.55554efb8e2ee220p-30L,0x9.ece38e11a4d17590p-24L,0xc.aa9811642fbdd110p-30L,0xc.2ce2c303dd338fa0p-24L,0xd.fe6fc58a1cc74c50p-30L,0xe.acc7661a59aa2de0p-24L,0xf.4b871617fff5fe90p-30L,0x8.b5efbf4d6577eb10p-23L,0x8.4445f0365ed59870p-29L,0xa.3408a2db9e5b7950p-23L,0x8.d57c4327fb179c40p-29L,0xb.ceae5db7d77fc1a0p-23L,0x9.54bd729046f1af30p-29L,0xd.82edd3490b0b8ef0p-23L,0x9.bf5ed3c497b926a0p-29L,0xf.4d1fffec60a19e50p-23L,0xa.14b42919ed0e7bf0p-29L,0x8.94a8e3980892bf10p-22L,0xa.54bd729046f1af30p-29L,0x9.89c1f9e9b35dc6c0p-22L,0xa.8026edd2a5c246e0p-29L,0xa.83e1b4b24d23ad70p-22L,0xa.999b458bb42aedc0p-29L,0xb.8134922069b5d190p-22L,0xa.a5c38b0bfffaff50p-29L,0xc.804103e7862798b0p-22L,0xa.a9e28d6fb90e50d0p-29L,0xd.80070a07a27902c0p-22L,0xa.aaa15e076d343de0p-29L,0xe.800032cd4196aa50p-22L,0xa.aaaaa77dc7177110p-29L,0xf.80000009cfaf30d0p-22L,0x8.3ffffffb18286790p-21L,0x8.bfffe6995f34aad0p-21L,0x9.3ffc7afc2ec37ea0p-21L,0x9.bfdf7e0c3cec33b0p-21L,0xa.3f65b6efcb251730p-21L,0xa.be0f25a6d96e2950p-21L,0xb.3b1f030b26511ca0p-21L,0xb.b5ab8e33fbb6a080p-21L,0xc.2cb80004e7d79870p-21L,0xc.9f448b2dbd3d1c40p-21L,0xd.0c5468920a200fa0p-21L,0xd.72fdd749186921b0p-21L,0xd.d284102ca6a20540p-21L,0xe.2a67133cb4caba40p-21L,0xe.7a63a79f84598e10p-21L,0xe.c2638e3dcb65d150p-21L,0xf.02638e3dcb65d150p-21L,0xf.3a63a79f84598e10p-21L,0xf.6a67133cb4caba40p-21L,0xf.9284102ca6a20540p-21L,0xf.b2fdd749186921b0p-21L,0xf.cc5468920a200fa0p-21L,0xf.df448b2dbd3d1c40p-21L,0xf.ecb80004e7d79870p-21L,0xf.f5ab8e33fbb6a080p-21L,0xf.fb1f030b26511ca0p-21L,0xf.fe0f25a6d96e2950p-21L,0xf.ff65b6efcb251730p-21L,0xf.ffdf7e0c3cec33b0p-21L,0xf.fffc7afc2ec37ea0p-21L,0xf.ffffe6995f34aad0p-21L,0xf.fffffffb18286790p-21L},
	U[][11] = {
		{-u[0],u[1],u[2],u[3],u[4],u[5],u[6],u[7],u[8],0xc.b10600a610025ec0p-54L,0xd.d212c67df54bad20p-55L},
		{u[0],-u[1],u[2],u[9],u[10],u[11],u[12],u[13],u[14],0xb.d31d19c6aec8f3d0p-43L,0xe.a56c82100aeb1570p-44L},
		{u[0],-u[1],-u[2],u[9],u[15],u[16],u[17],u[18],u[19],0x9.afd5ffd7ff4c4510p-37L,0xe.962c35651b0097b0p-38L},
		{-u[0],u[1],-u[2],u[3],u[20],u[21],u[22],u[23],u[24],0xf.aca626772787e9f0p-34L,0xe.d8747d348079a5b0p-34L},
		{u[0],-u[1],-u[2],-u[3],u[20],u[25],u[26],u[27],u[28],0xc.4fd1c1f48cf67c40p-31L,0xe.8ecc513303dc21e0p-31L},
		{-u[0],u[1],-u[2],-u[9],u[15],u[29],u[30],u[31],u[32],0xc.8ec63d7820ec5930p-29L,0x9.154597303d972750p-28L},
		{-u[0],u[1],u[2],-u[9],u[10],u[33],u[34],u[35],u[36],0x9.a99feaa472ad1e20p-27L,0x8.5de06c0ad9b87990p-26L},
		{u[0],-u[1],u[2],-u[3],u[4],u[37],u[38],u[39],u[40],0xc.378088c0608486c0p-26L,0xc.6c8c4f9b8883bcd0p-25L},
		{u[0],-u[1],-u[2],-u[3],-u[4],u[37],u[41],u[42],u[43],0xd.5d8760d1f75eb520p-25L,0xf.b74e022ae6a98660p-24L},
		{-u[0],u[1],-u[2],-u[9],-u[10],u[33],u[44],u[45],u[46],0xd.17dea7ff39004e70p-24L,0x8.c9153ca10b583520p-22L},
		{-u[0],u[1],u[2],-u[9],-u[15],u[29],u[47],u[48],u[49],0xb.c473fc8419673fa0p-23L,0x8.e8dd4f660a3793a0p-21L},
		{u[0],-u[1],u[2],-u[3],-u[20],u[25],u[50],u[51],u[52],0x9.dfb621c4887f5ed0p-22L,0x8.5a5cbe6ab9a39020p-20L},
		{-u[0],u[1],u[2],u[3],-u[20],u[21],u[53],u[54],u[55],0xf.aafaca6267727880p-22L,0xe.af816f06796aed50p-20L},
		{u[0],-u[1],u[2],u[9],-u[15],u[16],u[56],u[57],u[58],0xb.dd42936438bb8d80p-21L,0xc.3c157934e9556270p-19L},
		{u[0],-u[1],-u[2],u[9],-u[10],u[11],u[59],u[60],u[61],0x8.a2b8fb3473171b90p-20L,0x9.bd60f7a93235d440p-18L},
		{-u[0],u[1],-u[2],u[3],-u[4],u[5],u[62],u[63],u[64],0xc.26d555588196d580p-20L,0xe.e9ef3435acfea590p-18L},
		{u[0],-u[1],-u[2],-u[3],-u[4],-u[5],u[62],u[65],u[66],0x8.4d78e38ca2c2ce20p-19L,0xb.09db2853ba0d8bb0p-17L},
		{-u[0],u[1],-u[2],-u[9],-u[10],-u[11],u[59],u[67],u[68],0xb.0f87109eaa02ab20p-19L,0xf.dd5b267f43c594d0p-17L},
		{-u[0],u[1],u[2],-u[9],-u[15],-u[16],u[56],u[69],u[70],0xe.6992e95fd55f5580p-19L,0xb.1bbb92b4d60e3a80p-16L},
		{u[0],-u[1],u[2],-u[3],-u[20],-u[21],u[53],u[71],u[72],0x9.35c21a764b4ff4f0p-18L,0xf.341488b7840875f0p-16L},
		{-u[0],u[1],u[2],u[3],-u[20],-u[25],u[50],u[73],u[74],0xb.92766500293f2680p-18L,0xa.31d2e5f355cd1c80p-15L},
		{u[0],-u[1],u[2],u[9],-u[15],-u[29],u[47],u[75],u[76],0xe.524e273850fbe270p-18L,0xd.6d153c5a09effac0p-15L},
		{u[0],-u[1],-u[2],u[9],-u[10],-u[33],u[44],u[77],u[78],0x8.be09263e3a718da0p-17L,0x8.b2badc5912d274a0p-14L},
		{-u[0],u[1],-u[2],u[3],-u[4],-u[37],u[41],u[79],u[80],0xa.8adb5c2d66ec2f80p-17L,0xb.1b187e2b35645510p-14L},
		{-u[0],u[1],u[2],u[3],u[4],-u[37],u[38],u[81],u[82],0xc.921d2349d8b34bf0p-17L,0xd.fdf11fc2d6ff4960p-14L},
		{u[0],-u[1],u[2],u[9],u[10],-u[33],u[34],u[83],u[84],0xe.d5ce7b938fc6e2f0p-17L,0x8.b51127e6ee8fb150p-13L},
		{u[0],-u[1],-u[2],u[9],u[15],-u[29],u[30],u[85],u[86],0x8.abb7fb9530b0bfc0p-16L,0xa.b77cd535d90b25e0p-13L},
		{-u[0],u[1],-u[2],u[3],u[20],-u[25],u[26],u[87],u[88],0xa.0c03d2239888ad30p-16L,0xd.0e0ac024db6932c0p-13L},
		{u[0],-u[1],-u[2],-u[3],u[20],-u[21],u[22],u[89],u[90],0xb.8c18869d92d3fd40p-16L,0xf.c0a404fc8777dce0p-13L},
		{-u[0],u[1],-u[2],-u[9],u[15],-u[16],u[17],u[91],u[92],0xd.2c1c24486c730720p-16L,0x9.6ba003a58b0d5940p-12L},
		{-u[0],u[1],u[2],-u[9],u[10],-u[11],u[12],u[93],u[94],0xe.ec1c704cb8ce8e40p-16L,0xb.2cee38f233a565a0p-12L},
		{u[0],-u[1],u[2],-u[3],u[4],-u[5],u[6],u[95],u[96],0x8.660e38e374d6d790p-15L,0xd.283c71c71e2c0970p-12L},
		{u[0],-u[1],-u[2],-u[3],-u[4],-u[5],-u[6],u[95],u[97],0x9.660e38e374d6d790p-15L,0xf.618aaaaaa8f06850p-12L},
		{-u[0],u[1],-u[2],-u[9],-u[10],-u[11],-u[12],u[93],u[98],0xa.760e38265c674720p-15L,0x8.ee6c71bfc9bb8610p-11L},
		{-u[0],u[1],u[2],-u[9],-u[15],-u[16],-u[17],u[91],u[99],0xb.960e122436398390p-15L,0xa.4f138c661e078c40p-11L},
		{u[0],-u[1],u[2],-u[3],-u[20],-u[21],-u[22],u[89],u[100],0xc.c60c434ec969fea0p-15L,0xb.d4ba8cf9c1b041b0p-11L},
		{-u[0],u[1],u[2],u[3],-u[20],-u[25],-u[26],u[87],u[101],0xe.0601e911cc445690p-15L,0xd.8160de2facb3ec30p-11L},
		{u[0],-u[1],u[2],u[9],-u[15],-u[29],-u[30],u[85],u[102],0xf.55dbfdca98585fe0p-15L,0xf.570458eb6d4b6f70p-11L},
		{u[0],-u[1],-u[2],u[9],-u[10],-u[33],-u[34],u[83],u[103],0x8.5ab9cf7271f8dc60p-14L,0x8.abcfa21f93f52640p-10L},
		{-u[0],u[1],-u[2],u[3],-u[4],-u[37],-u[38],u[81],u[104],0x9.1243a4693b166980p-14L,0x9.c292b520445727e0p-10L},
		{-u[0],u[1],u[2],u[3],u[4],-u[37],-u[41],u[79],u[105],0x9.d15b6b85acdd85f0p-14L,0xa.f0c03f39be70d720p-10L},
		{u[0],-u[1],u[2],u[9],u[10],-u[33],-u[44],u[77],u[106],0xa.97c124c7c74e31b0p-14L,0xc.37461956e099f520p-10L},
		{u[0],-u[1],-u[2],u[9],u[15],-u[29],-u[47],u[75],u[107],0xb.6524e273850fbe20p-14L,0xd.97091d39a1779ca0p-10L},
		{-u[0],u[1],-u[2],u[3],u[20],-u[25],-u[50],u[73],u[108],0xc.392766500293f270p-14L,0xf.10e32fecd718b390p-10L},
		{u[0],-u[1],-u[2],-u[3],u[20],-u[21],-u[53],u[71],u[109],0xd.135c21a764b4ff50p-14L,0x8.52d0ba7cc9db7d50p-9L},
		{-u[0],u[1],-u[2],-u[9],u[15],-u[16],-u[56],u[69],u[110],0xd.f34c974afeaafab0p-14L,0x9.2b016c68cf3771c0p-9L},
		{-u[0],u[1],u[2],-u[9],u[10],-u[11],-u[59],u[67],u[111],0xe.d87c3884f5501560p-14L,0xa.115b8867b99fc8a0p-9L},
		{u[0],-u[1],u[2],-u[3],u[4],-u[5],-u[62],u[65],u[112],0xf.c26bc71c65161670p-14L,0xb.062f0865e52980b0p-9L},
		{-u[0],u[1],u[2],u[3],u[4],u[5],-u[62],u[63],u[113],0x8.584daaaab1032db0p-13L,0xc.09c3ebf41e0d0ee0p-9L},
		{u[0],-u[1],u[2],u[9],u[10],u[11],-u[59],u[60],u[114],0x8.d14571f668e62e30p-13L,0xd.1c5a3312644a7350p-9L},
		{u[0],-u[1],-u[2],u[9],u[15],u[16],-u[56],u[57],u[115],0x9.4bdd42936438bb90p-13L,0xe.3e29de2feba938e0p-9L},
		{-u[0],u[1],-u[2],u[3],u[20],u[21],-u[53],u[54],u[116],0x9.c7d57d653133b940p-13L,0xf.6f62f360581460e0p-9L},
		{u[0],-u[1],-u[2],-u[3],u[20],u[25],-u[50],u[51],u[117],0xa.44efdb10e2443fb0p-13L,0x8.5816cbfb35c62ce0p-8L},
		{-u[0],u[1],-u[2],-u[9],u[15],u[29],-u[47],u[48],u[118],0xa.c2f11cff210659d0p-13L,0x9.00552adca1417560p-8L},
		{-u[0],u[1],u[2],-u[9],u[10],u[33],-u[44],u[45],u[119],0xb.41a2fbd4ffe72010p-13L,0x9.b0794d7229ed99c0p-8L},
		{u[0],-u[1],u[2],-u[3],u[4],u[37],-u[41],u[42],u[120],0xb.c0d5d8760d1f75f0p-13L,0xa.688cba791a46e070p-8L},
		{u[0],-u[1],-u[2],-u[3],-u[4],u[37],-u[38],u[39],u[121],0xc.4061bc0446030420p-13L,0xb.28963b80f4a402e0p-8L},
		{-u[0],u[1],-u[2],-u[9],-u[10],u[33],-u[34],u[35],u[122],0xc.c026a67faa91cab0p-13L,0xb.f09a5a4f016f10b0p-8L},
		{-u[0],u[1],u[2],-u[9],-u[15],u[29],-u[30],u[31],u[123],0xd.400c8ec63d7820f0p-13L,0xc.c09be072c2fec340p-8L},
		{u[0],-u[1],u[2],-u[3],-u[20],u[25],-u[26],u[27],u[124],0xd.c00313f4707d2340p-13L,0xd.989c54a983cf6110p-8L},
		{-u[0],u[1],u[2],u[3],-u[20],u[21],-u[22],u[23],u[125],0xe.40007d653133b940p-13L,0xe.789c6e10ff527a00p-8L},
		{u[0],-u[1],u[2],u[9],-u[15],u[16],-u[17],u[18],u[126],0xe.c00009afd5ffd800p-13L,0xf.609c718cc3c0f190p-8L},
		{u[0],-u[1],-u[2],u[9],-u[10],u[11],-u[12],u[13],u[127],0xf.4000002f4c746720p-13L,0x8.284e38e3190d7f80p-7L},
		{-u[0],u[1],-u[2],u[3],-u[4],u[5],-u[6],u[7],u[128],0xf.c000000006588300p-13L,0x8.a44e38e38e2b1180p-7L},
		{u[0],-u[1],-u[2],-u[3],-u[4],-u[5],-u[6],-u[7],u[128],0x8.1ffffffffcd3be80p-12L,0x9.244e38e38e2b1180p-7L},
		{-u[0],u[1],-u[2],-u[9],-u[10],-u[11],-u[12],-u[13],u[127],0x8.5fffffe859c5cc70p-12L,0x9.a84e38e3190d7f80p-7L},
		{-u[0],u[1],u[2],-u[9],-u[15],-u[16],-u[17],-u[18],u[126],0x8.9ffffb2815001400p-12L,0xa.304e38c661e078c0p-7L},
		{u[0],-u[1],u[2],-u[3],-u[20],-u[21],-u[22],-u[23],u[125],0x8.dfffc14d67662360p-12L,0xa.bc4e37087fa93d00p-7L},
		{-u[0],u[1],u[2],u[3],-u[20],-u[25],-u[26],-u[27],u[124],0x9.1ffe7605c7c16e60p-12L,0xb.4c4e2a54c1e7b090p-7L},
		{u[0],-u[1],u[2],u[9],-u[15],-u[29],-u[30],-u[31],u[123],0x9.5ff9b89ce143ef90p-12L,0xb.e04df039617f61a0p-7L},
		{u[0],-u[1],-u[2],u[9],-u[10],-u[33],-u[34],-u[35],u[122],0x9.9fecacc02ab71aa0p-12L,0xc.784d2d2780b78850p-7L},
		{-u[0],u[1],-u[2],u[3],-u[4],-u[37],-u[38],-u[39],u[121],0x9.dfcf21fddcfe7df0p-12L,0xd.144b1dc07a520170p-7L},
		{-u[0],u[1],u[2],u[3],u[4],-u[37],-u[41],-u[42],u[120],0xa.1f9513c4f9704510p-12L,0xd.b4465d3c8d237040p-7L},
		{u[0],-u[1],u[2],u[9],u[10],-u[33],-u[44],-u[45],u[119],0xa.5f2e8215800c7000p-12L,0xe.583ca6b914f6cce0p-7L},
		{u[0],-u[1],-u[2],u[9],u[15],-u[29],-u[47],-u[48],u[118],0xa.9e8771806f7cd320p-12L,0xf.002a956e50a0bab0p-7L},
		{-u[0],u[1],-u[2],u[3],u[20],-u[25],-u[50],-u[51],u[117],0xa.dd8812778edde030p-12L,0xf.ac0b65fd9ae31670p-7L},
		{u[0],-u[1],-u[2],-u[3],u[20],-u[21],-u[53],-u[54],u[116],0xb.1c15414d67662360p-12L,0x8.2dec5e6c0b028c20p-6L},
		{-u[0],u[1],-u[2],-u[9],u[15],-u[16],-u[56],-u[57],u[115],0xb.5a115eb64de3a240p-12L,0x8.87c53bc5fd752720p-6L},
		{-u[0],u[1],u[2],-u[9],u[10],-u[11],-u[59],-u[60],u[114],0xb.975d4704cb8ce8e0p-12L,0x8.e38b46624c894e70p-6L},
		{u[0],-u[1],u[2],-u[3],u[4],-u[5],-u[62],-u[63],u[113],0xb.d3d92aaaa77e6930p-12L,0x9.41387d7e83c1a1e0p-6L},
		{-u[0],u[1],u[2],u[3],u[4],u[5],-u[62],-u[65],u[112],0xc.0f650e38e6ba7a60p-12L,0x9.a0c5e10cbca53010p-6L},
		{u[0],-u[1],u[2],u[9],u[10],u[11],-u[59],-u[67],u[111],0xc.49e0f1dec2abfab0p-12L,0xa.022b710cf733f910p-6L},
		{u[0],-u[1],-u[2],u[9],u[15],u[16],-u[56],-u[69],u[110],0xc.832cda2d40554150p-12L,0xa.65602d8d19e6ee40p-6L},
		{-u[0],u[1],-u[2],u[3],u[20],u[21],-u[53],-u[71],u[109],0xc.bb28f79626d2c030p-12L,0xa.ca5a174f993b6fb0p-6L},
		{u[0],-u[1],-u[2],-u[3],u[20],u[25],-u[50],-u[73],u[108],0xc.f1b6266bff5b0360p-12L,0xb.310e32fecd718b40p-6L},
		{-u[0],u[1],-u[2],-u[9],u[15],u[29],-u[47],-u[75],u[107],0xd.26b6c7631ebc1070p-12L,0xb.997091d39a1779d0p-6L},
		{-u[0],u[1],u[2],-u[9],u[10],u[33],-u[44],-u[77],u[106],0xd.5a0fb6ce0e2c7390p-12L,0xc.037461956e099f50p-6L},
		{u[0],-u[1],u[2],-u[3],u[4],u[37],-u[41],-u[79],u[105],0xd.8ba9251e94c89e80p-12L,0xc.6f0c03f39be70d70p-6L},
		{u[0],-u[1],-u[2],-u[3],-u[4],u[37],-u[38],-u[81],u[104],0xd.bb6f16e5b13a65a0p-12L,0xc.dc292b5204457280p-6L},
		{-u[0],u[1],-u[2],-u[9],-u[10],u[33],-u[34],-u[83],u[103],0xd.e9518c236381c8f0p-12L,0xd.4abcfa21f93f5260p-6L},
		{-u[0],u[1],u[2],-u[9],-u[15],u[29],-u[30],-u[85],u[102],0xe.15448046acf4f400p-12L,0xd.bab822c75b6a5b80p-6L},
		{u[0],-u[1],u[2],-u[3],-u[20],u[25],-u[26],-u[87],u[101],0xe.3f3fc2ddc6777530p-12L,0xe.2c0b06f17d659f60p-6L},
		{-u[0],u[1],u[2],u[3],-u[20],u[21],-u[22],-u[89],u[100],0xe.673e779626d2c030p-12L,0xe.9ea5d467ce0d8210p-6L},
		{u[0],-u[1],u[2],u[9],-u[15],u[16],-u[17],-u[91],u[99],0xe.8d3e3dbb7938cf90p-12L,0xf.12789c6330f03c60p-6L},
		{u[0],-u[1],-u[2],u[9],-u[10],u[11],-u[12],-u[93],u[98],0xe.b13e38fb34731720p-12L,0xf.8773638dfe4ddc30p-6L},
		{-u[0],u[1],-u[2],u[3],-u[4],u[5],-u[6],-u[95],u[97],0xe.d33e38e391652510p-12L,0xf.fd862aaaaaa3c1a0p-6L},
		{-u[0],u[1],u[2],u[3],u[4],u[5],u[6],-u[95],u[96],0xe.f33e38e391652510p-12L,0x8.3a5078e38e3c5810p-5L},
		{u[0],-u[1],u[2],u[9],u[10],u[11],u[12],-u[93],u[94],0xf.113e38fb34731720p-12L,0x8.7659dc71e4674ad0p-5L},
		{u[0],-u[1],-u[2],u[9],u[15],u[16],u[17],-u[91],u[92],0xf.2d3e3dbb7938cf90p-12L,0x8.b2d740074b161ab0p-5L},
		{-u[0],u[1],-u[2],u[3],u[20],u[21],u[22],-u[89],u[90],0xf.473e779626d2c030p-12L,0x8.efc0a404fc8777e0p-5L},
		{u[0],-u[1],-u[2],-u[3],u[20],u[25],u[26],-u[87],u[88],0xf.5f3fc2ddc6777530p-12L,0x9.2d0e0ac024db6930p-5L},
		{-u[0],u[1],-u[2],-u[9],u[15],u[29],u[30],-u[85],u[86],0xf.75448046acf4f400p-12L,0x9.6ab77cd535d90b20p-5L},
		{-u[0],u[1],u[2],-u[9],u[10],u[33],u[34],-u[83],u[84],0xf.89518c236381c8f0p-12L,0x9.a8b51127e6ee8fb0p-5L},
		{u[0],-u[1],u[2],-u[3],u[4],u[37],u[38],-u[81],u[82],0xf.9b6f16e5b13a65a0p-12L,0x9.e6fef88fe16b7fa0p-5L},
		{u[0],-u[1],-u[2],-u[3],-u[4],u[37],u[41],-u[79],u[80],0xf.aba9251e94c89e80p-12L,0xa.258d8c3f159ab230p-5L},
		{-u[0],u[1],-u[2],-u[9],-u[10],u[33],u[44],-u[77],u[78],0xf.ba0fb6ce0e2c7390p-12L,0xa.64595d6e2c896940p-5L},
		{-u[0],u[1],u[2],-u[9],-u[15],u[29],u[47],-u[75],u[76],0xf.c6b6c7631ebc1070p-12L,0xa.a35b454f16827c00p-5L},
		{u[0],-u[1],u[2],-u[3],-u[20],u[25],u[50],-u[73],u[74],0xf.d1b6266bff5b0360p-12L,0xa.e28c74b97cd57340p-5L},
		{-u[0],u[1],u[2],u[3],-u[20],u[21],u[53],-u[71],u[72],0xf.db28f79626d2c030p-12L,0xb.21e6829116f08110p-5L},
		{u[0],-u[1],u[2],u[9],-u[15],u[16],u[56],-u[69],u[70],0xf.e32cda2d40554150p-12L,0xb.61637772569ac1c0p-5L},
		{u[0],-u[1],-u[2],u[9],-u[10],u[11],u[59],-u[67],u[68],0xf.e9e0f1dec2abfab0p-12L,0xb.a0fdd5b267f43c60p-5L},
		{-u[0],u[1],-u[2],u[3],-u[4],u[5],u[62],-u[65],u[66],0xf.ef650e38e6ba7a60p-12L,0xb.e0b09db2853ba0e0p-5L},
		{u[0],-u[1],-u[2],-u[3],-u[4],-u[5],u[62],-u[63],u[64],0xf.f3d92aaaa77e6930p-12L,0xc.20774f79a1ad67f0p-5L},
		{-u[0],u[1],-u[2],-u[9],-u[10],-u[11],u[59],-u[60],u[61],0xf.f75d4704cb8ce8e0p-12L,0xc.604deb07bd4991b0p-5L},
		{-u[0],u[1],u[2],-u[9],-u[15],-u[16],u[56],-u[57],u[58],0xf.fa115eb64de3a240p-12L,0xc.a030f055e4d3a550p-5L},
		{u[0],-u[1],u[2],-u[3],-u[20],-u[21],u[53],-u[54],u[55],0xf.fc15414d67662360p-12L,0xc.e01d5f02de0cf2d0p-5L},
		{-u[0],u[1],u[2],u[3],-u[20],-u[25],u[50],-u[51],u[52],0xf.fd8812778edde030p-12L,0xd.2010b4b97cd57340p-5L},
		{u[0],-u[1],u[2],u[9],-u[15],-u[29],u[47],-u[48],u[49],0xf.fe8771806f7cd320p-12L,0xd.6008e8dd4f660a30p-5L},
		{u[0],-u[1],-u[2],u[9],-u[10],-u[33],u[44],-u[45],u[46],0xf.ff2e8215800c7000p-12L,0xd.a004648a9e5085b0p-5L},
		{-u[0],u[1],-u[2],u[3],-u[4],-u[37],u[41],-u[42],u[43],0xf.ff9513c4f9704510p-12L,0xd.e001f6e9c0455cd0p-5L},
		{-u[0],u[1],u[2],u[3],u[4],-u[37],u[38],-u[39],u[40],0xf.ffcf21fddcfe7df0p-12L,0xe.2000c6c8c4f9b890p-5L},
		{u[0],-u[1],u[2],u[9],u[10],-u[33],u[34],-u[35],u[36],0xf.ffecacc02ab71aa0p-12L,0xe.600042ef036056d0p-5L},
		{u[0],-u[1],-u[2],u[9],u[15],-u[29],u[30],-u[31],u[32],0xf.fff9b89ce143ef90p-12L,0xe.a000122a8b2e6080p-5L},
		{-u[0],u[1],-u[2],u[3],u[20],-u[25],u[26],-u[27],u[28],0xf.fffe7605c7c16e60p-12L,0xe.e00003a3b3144cc0p-5L},
		{u[0],-u[1],-u[2],-u[3],u[20],-u[21],u[22],-u[23],u[24],0xf.ffffc14d67662360p-12L,0xf.20000076c3a3e9a0p-5L},
		{-u[0],u[1],-u[2],-u[9],u[15],-u[16],u[17],-u[18],u[19],0xf.fffffb2815001400p-12L,0xf.600000074b161ab0p-5L},
		{-u[0],u[1],u[2],-u[9],u[10],-u[11],u[12],-u[13],u[14],0xf.ffffffe859c5cc70p-12L,0xf.a00000001d4ad900p-5L},
		{u[0],-u[1],u[2],-u[3],u[4],-u[5],u[6],-u[7],u[8],0xf.fffffffffcd3be80p-12L,0xf.e000000000037480p-5L}
	};
	long double t = 256.0L*x;
	int s = (int)t;
	s -= (s >> 7); //0.5 exception case
	long double f = 4.0L*(t - (long double)s) - 2.0L,
    b = U[s][0],
    a = f*b,
	c;
    for (int j = 1; j < 10; ++j) {
        c = b;
        b = a;
        a = f*b + U[s][j] - c;
    }
    return 0.5L*f*a - b + U[s][10];	
}
long double fab(long double x){
	if (x <= 0.0L)
		return 0.0L;
	if (x >= 1.0L)
		return 1.0L;
	if (x > 0.5L)
		return 1.0L - fab_eval(1.0L - x);
	return fab_eval(x);
}
long double fabd(long double x){
	if (x <= 0.0L || x >= 1.0L)
		return 0.0L;
	if (x > 0.5L)
		return 2.0L*fab(2.0L*(1.0L - x));
	return 2.0L*fab(2.0L*x);
}
long double fabdd(long double x){
	if (x <= 0.0L || x >= 1.0L)
		return 0.0L;
	if (x > 0.5L)
		return -4.0L*fabd(2.0L*(1.0L - x));
	return 4.0L*fabd(2.0L*x);
}
long double fabi(long double x){
	if (x <= 0.0L)
		return 0.0L;
	if (x >= 1.0L)
		return x - 0.5L;
	if (x > 0.5L)
		return x - 0.5L + fab_eval(0.5L*(1.0L - x));
	return fab_eval(0.5L*x);
}
long double fabii(long double x){
	if (x <= 0.0L)
		return 0.0L;
	if (x >= 1.0L)
		return 0.5L*(x - 0.5L)*(x - 0.5L) + 1.0L/72.0L;
	if (x > 0.5L)
		return 0.5L*(x - 0.5L)*(x - 0.5L) + 1.0L/72.0L - 2.0L*fab_eval(0.25L*(1.0L - x));
	return 2.0L*fab_eval(0.25L*x);
}
#endif
