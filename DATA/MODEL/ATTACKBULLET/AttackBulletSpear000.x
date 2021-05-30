xof 0302txt 0064
template Header {
 <3D82AB43-62DA-11cf-AB39-0020AF71E433>
 WORD major;
 WORD minor;
 DWORD flags;
}

template Vector {
 <3D82AB5E-62DA-11cf-AB39-0020AF71E433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template Coords2d {
 <F6F23F44-7686-11cf-8F52-0040333594A3>
 FLOAT u;
 FLOAT v;
}

template Matrix4x4 {
 <F6F23F45-7686-11cf-8F52-0040333594A3>
 array FLOAT matrix[16];
}

template ColorRGBA {
 <35FF44E0-6C7C-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <D3E16E81-7835-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template IndexedColor {
 <1630B820-7842-11cf-8F52-0040333594A3>
 DWORD index;
 ColorRGBA indexColor;
}

template Boolean {
 <4885AE61-78E8-11cf-8F52-0040333594A3>
 WORD truefalse;
}

template Boolean2d {
 <4885AE63-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template MaterialWrap {
 <4885AE60-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template TextureFilename {
 <A42790E1-7810-11cf-8F52-0040333594A3>
 STRING filename;
}

template Material {
 <3D82AB4D-62DA-11cf-AB39-0020AF71E433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshFace {
 <3D82AB5F-62DA-11cf-AB39-0020AF71E433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template MeshFaceWraps {
 <4885AE62-78E8-11cf-8F52-0040333594A3>
 DWORD nFaceWrapValues;
 Boolean2d faceWrapValues;
}

template MeshTextureCoords {
 <F6F23F40-7686-11cf-8F52-0040333594A3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template MeshMaterialList {
 <F6F23F42-7686-11cf-8F52-0040333594A3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material]
}

template MeshNormals {
 <F6F23F43-7686-11cf-8F52-0040333594A3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template MeshVertexColors {
 <1630B821-7842-11cf-8F52-0040333594A3>
 DWORD nVertexColors;
 array IndexedColor vertexColors[nVertexColors];
}

template Mesh {
 <3D82AB44-62DA-11cf-AB39-0020AF71E433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

Header{
1;
0;
1;
}

Mesh {
 117;
 0.34811;82.89807;-1.51834;,
 0.68974;82.89809;-1.94173;,
 0.05756;66.32687;-2.28101;,
 -0.91625;66.32684;-1.51838;,
 1.37311;82.89809;-1.94173;,
 1.71485;82.89807;-1.51834;,
 2.97921;66.32684;-1.51838;,
 2.00530;66.32687;-2.28101;,
 -1.06788;49.56149;-2.94089;,
 -3.16712;49.56149;-1.51839;,
 5.23008;49.56149;-1.51839;,
 3.13072;49.56149;-2.94089;,
 -1.48076;45.67892;-3.67043;,
 -3.99296;45.67895;-2.31599;,
 6.05581;45.67895;-2.31599;,
 3.54362;45.67892;-3.67043;,
 0.23765;44.21607;-3.67041;,
 -0.55610;44.21608;-2.79308;,
 2.61896;44.21608;-2.79308;,
 1.82519;44.21607;-3.67041;,
 -0.74929;39.65582;-3.67040;,
 -2.53001;39.65580;-2.79311;,
 4.59285;39.65580;-2.79311;,
 2.81214;39.65582;-3.67040;,
 -1.20851;37.03768;-3.67041;,
 -3.44843;37.03770;-2.79308;,
 5.51128;37.03770;-2.79308;,
 3.27135;37.03768;-3.67041;,
 6.05581;45.67895;-2.31599;,
 6.05581;45.67892;-0.72075;,
 2.61896;44.21606;-0.24367;,
 2.61896;44.21608;-2.79308;,
 4.59285;39.65583;-0.24367;,
 4.59285;39.65580;-2.79311;,
 5.51128;37.03768;-0.24365;,
 5.51128;37.03770;-2.79308;,
 6.05581;45.67892;-0.72075;,
 3.54362;45.67893;0.63368;,
 1.82519;44.21610;0.63366;,
 2.61896;44.21606;-0.24367;,
 -1.48076;45.67893;0.63368;,
 -3.99296;45.67892;-0.72075;,
 -0.55610;44.21606;-0.24367;,
 0.23765;44.21610;0.63366;,
 2.81214;39.65583;0.63368;,
 4.59285;39.65583;-0.24367;,
 -2.53001;39.65583;-0.24367;,
 -0.74929;39.65583;0.63368;,
 3.27135;37.03768;0.63368;,
 5.51128;37.03768;-0.24365;,
 -3.44843;37.03768;-0.24365;,
 -1.20851;37.03768;0.63368;,
 -3.99296;45.67892;-0.72075;,
 -3.99296;45.67895;-2.31599;,
 -0.55610;44.21608;-2.79308;,
 -0.55610;44.21606;-0.24367;,
 -2.53001;39.65580;-2.79311;,
 -2.53001;39.65583;-0.24367;,
 -3.44843;37.03770;-2.79308;,
 -3.44843;37.03768;-0.24365;,
 1.03143;91.47135;-1.51833;,
 1.37311;82.89810;-1.09503;,
 0.68974;82.89810;-1.09503;,
 2.00530;66.32687;-0.75573;,
 0.05756;66.32687;-0.75573;,
 3.13072;49.56144;-0.09584;,
 -1.06788;49.56144;-0.09584;,
 2.98360;33.84981;-2.57045;,
 4.19011;33.84983;-1.92022;,
 6.69298;31.45854;-2.17351;,
 4.53045;31.45853;-3.23357;,
 4.19011;33.84983;-1.11652;,
 6.69298;31.45855;-0.86323;,
 2.98360;33.84983;-0.46632;,
 4.53045;31.45856;0.19681;,
 -0.92075;33.84983;-0.46632;,
 -2.12726;33.84983;-1.11652;,
 -4.63013;31.45855;-0.86323;,
 -2.46760;31.45856;0.19681;,
 -2.12726;33.84983;-1.92022;,
 -4.63013;31.45854;-2.17351;,
 -0.92075;33.84981;-2.57045;,
 -2.46760;31.45853;-3.23357;,
 3.34995;28.77653;-1.82078;,
 2.46435;28.77651;-2.31011;,
 3.34995;28.77652;-1.21596;,
 2.46435;28.77653;-0.72663;,
 -1.28709;28.77652;-1.21596;,
 -0.40150;28.77653;-0.72663;,
 -1.28709;28.77653;-1.82078;,
 -0.40150;28.77651;-2.31011;,
 1.03143;28.77651;-2.49700;,
 1.73016;23.70105;-2.48011;,
 1.03143;23.70106;-2.70710;,
 2.16200;23.70104;-1.88572;,
 2.16200;23.70104;-1.15103;,
 1.73016;23.70106;-0.55666;,
 1.03143;28.77653;-0.53974;,
 1.03143;23.70106;-0.32961;,
 0.33269;23.70106;-0.55666;,
 -0.09915;23.70104;-1.15103;,
 -0.09915;23.70104;-1.88572;,
 0.33269;23.70105;-2.48011;,
 1.03143;28.77651;-2.49700;,
 1.03143;23.70106;-2.70710;,
 1.73016;-64.65339;-2.48006;,
 1.03143;-64.65343;-2.70711;,
 2.16200;-64.65341;-1.88574;,
 2.16200;-64.65341;-1.15102;,
 1.73016;-64.65349;-0.55666;,
 1.03143;-64.65346;-0.32969;,
 0.33269;-64.65349;-0.55666;,
 -0.09915;-64.65341;-1.15102;,
 -0.09915;-64.65341;-1.88574;,
 0.33269;-64.65339;-2.48006;,
 1.03143;-64.65343;-2.70711;,
 0.99539;-64.96577;-1.54650;;
 
 106;
 4;0,1,2,3;,
 4;4,5,6,7;,
 4;3,2,8,9;,
 4;7,6,10,11;,
 4;9,8,12,13;,
 4;11,10,14,15;,
 4;13,12,16,17;,
 4;15,14,18,19;,
 4;17,16,20,21;,
 4;19,18,22,23;,
 4;21,20,24,25;,
 4;23,22,26,27;,
 4;28,29,30,31;,
 4;31,30,32,33;,
 4;33,32,34,35;,
 4;36,37,38,39;,
 4;40,41,42,43;,
 4;39,38,44,45;,
 4;43,42,46,47;,
 4;45,44,48,49;,
 4;47,46,50,51;,
 4;52,53,54,55;,
 4;55,54,56,57;,
 4;57,56,58,59;,
 3;0,60,1;,
 3;4,60,5;,
 3;61,5,60;,
 3;0,62,60;,
 3;14,10,29;,
 3;9,13,52;,
 4;5,61,63,6;,
 4;3,64,62,0;,
 4;6,63,65,10;,
 4;10,65,37,29;,
 4;64,3,9,66;,
 4;66,9,52,40;,
 4;67,68,69,70;,
 4;68,71,72,69;,
 4;71,73,74,72;,
 4;75,76,77,78;,
 4;76,79,80,77;,
 4;79,81,82,80;,
 4;70,69,83,84;,
 4;69,72,85,83;,
 4;72,74,86,85;,
 4;78,77,87,88;,
 4;77,80,89,87;,
 4;80,82,90,89;,
 4;91,84,92,93;,
 4;84,83,94,92;,
 4;83,85,95,94;,
 4;85,86,96,95;,
 4;86,97,98,96;,
 4;97,88,99,98;,
 4;88,87,100,99;,
 4;87,89,101,100;,
 4;89,90,102,101;,
 4;90,103,104,102;,
 4;93,92,105,106;,
 4;92,94,107,105;,
 4;94,95,108,107;,
 4;95,96,109,108;,
 4;96,98,110,109;,
 4;98,99,111,110;,
 4;99,100,112,111;,
 4;100,101,113,112;,
 4;101,102,114,113;,
 4;102,104,115,114;,
 3;105,107,116;,
 3;116,107,108;,
 3;116,108,109;,
 3;116,109,110;,
 3;116,110,111;,
 3;116,112,113;,
 3;116,111,112;,
 3;116,113,114;,
 3;116,114,115;,
 3;116,115,105;,
 4;25,24,81,79;,
 4;59,58,79,76;,
 4;51,50,76,75;,
 4;49,48,73,71;,
 4;35,34,71,68;,
 4;27,26,68,67;,
 3;4,1,60;,
 3;60,62,61;,
 4;61,62,64,63;,
 4;63,64,66,65;,
 4;65,66,40,37;,
 4;37,40,43,38;,
 4;38,43,47,44;,
 4;44,47,51,48;,
 4;48,51,75,73;,
 4;73,75,78,74;,
 4;74,78,88,97;,
 3;74,97,86;,
 3;82,103,90;,
 4;82,70,84,103;,
 4;81,67,70,82;,
 4;24,27,67,81;,
 4;20,23,27,24;,
 4;1,4,7,2;,
 4;2,7,11,8;,
 4;8,11,15,12;,
 4;12,15,19,16;,
 4;16,19,23,20;;
 
 MeshMaterialList {
  3;
  106;
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1;;
  Material {
   1.000000;0.984000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   1.000000;0.984000;0.000000;;
  }
  Material {
   0.000000;0.090000;0.584000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.090000;0.584000;;
  }
  Material {
   1.000000;0.388000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   1.000000;0.388000;0.000000;;
  }
 }
 MeshNormals {
  137;
  -0.740217;0.053564;-0.670232;,
  -0.404511;0.048374;-0.913253;,
  0.404452;0.048372;-0.913279;,
  -0.646211;0.059534;-0.760833;,
  -0.343728;0.047616;-0.937861;,
  0.343696;0.047614;-0.937873;,
  -0.769526;0.194493;-0.608278;,
  -0.285839;0.141193;-0.947819;,
  0.285827;0.141191;-0.947823;,
  -0.546806;-0.232085;-0.804450;,
  -0.273017;-0.063892;-0.959885;,
  0.273013;-0.063893;-0.959886;,
  -0.586827;-0.263907;-0.765498;,
  -0.296309;-0.133260;-0.945750;,
  0.296307;-0.133260;-0.945750;,
  -0.822965;0.290039;-0.488473;,
  -0.259326;0.072565;-0.963060;,
  0.259325;0.072565;-0.963060;,
  -0.408662;-0.128596;-0.903581;,
  -0.207581;-0.150431;-0.966582;,
  0.207581;-0.150431;-0.966582;,
  0.740129;0.053564;-0.670328;,
  0.646157;0.059531;-0.760879;,
  0.769518;0.194481;-0.608292;,
  0.546798;-0.232087;-0.804455;,
  0.586823;-0.263907;-0.765501;,
  0.822965;0.290039;-0.488474;,
  0.408662;-0.128596;-0.903581;,
  0.404422;0.048366;0.913293;,
  -0.404481;0.048368;0.913266;,
  0.343690;0.047614;0.937875;,
  -0.343723;0.047616;0.937863;,
  0.285832;0.141191;0.947821;,
  -0.285843;0.141194;0.947817;,
  0.454285;-0.832881;0.316125;,
  0.273011;-0.063890;0.959887;,
  -0.273015;-0.063889;0.959886;,
  0.296307;-0.133254;0.945751;,
  -0.296309;-0.133254;0.945751;,
  0.822968;0.290041;0.488466;,
  0.259331;0.072569;0.963058;,
  -0.259333;0.072569;0.963058;,
  0.999615;-0.027749;-0.000001;,
  0.207581;-0.150435;0.966581;,
  -0.207581;-0.150436;0.966581;,
  -0.454287;-0.832880;0.316123;,
  -0.586827;-0.263899;0.765501;,
  -0.822969;0.290042;0.488465;,
  -0.408662;-0.128596;0.903581;,
  -0.430331;0.061626;-0.900565;,
  0.219063;0.020078;-0.975504;,
  0.604872;0.669367;-0.431368;,
  0.604870;0.669368;0.431368;,
  0.219059;0.020074;0.975505;,
  -0.219059;0.020074;0.975505;,
  -0.604870;0.669368;0.431368;,
  -0.604872;0.669367;-0.431368;,
  -0.219064;0.020078;-0.975504;,
  0.166984;0.151055;-0.974320;,
  0.126873;0.003384;0.991913;,
  -0.166982;0.151059;0.974319;,
  -0.126875;0.003378;-0.991913;,
  -0.015259;-0.177539;-0.983995;,
  0.350483;-0.256442;-0.900777;,
  0.764145;-0.481988;-0.428685;,
  0.764143;-0.481987;0.428688;,
  0.365166;-0.273717;0.889794;,
  0.015261;-0.177536;0.983996;,
  -0.350488;-0.256436;0.900777;,
  -0.764144;-0.481987;0.428687;,
  -0.764145;-0.481988;-0.428684;,
  -0.365162;-0.273723;-0.889794;,
  0.000002;0.014036;-0.999901;,
  0.522266;-0.019496;-0.852560;,
  0.928771;-0.088918;-0.359829;,
  0.928772;-0.088919;0.359828;,
  0.522271;-0.019497;0.852557;,
  0.000002;0.014035;0.999902;,
  -0.522270;-0.019497;0.852557;,
  -0.928772;-0.088918;0.359828;,
  -0.928772;-0.088918;-0.359829;,
  -0.522265;-0.019496;-0.852560;,
  0.000002;-0.000000;-1.000000;,
  0.587772;-0.000000;-0.809026;,
  0.951054;-0.000000;-0.309025;,
  0.951055;0.000000;0.309022;,
  0.587770;-0.000000;0.809028;,
  0.000002;-0.000000;1.000000;,
  -0.587769;-0.000000;0.809029;,
  -0.951055;0.000000;0.309021;,
  -0.951054;-0.000000;-0.309025;,
  -0.587771;-0.000000;-0.809028;,
  -0.004095;-0.999986;-0.003227;,
  0.391639;-0.920119;-0.000012;,
  0.917719;0.397231;-0.000001;,
  0.840925;0.319125;0.437040;,
  0.408662;-0.128596;0.903581;,
  -0.391640;-0.920119;-0.000012;,
  -0.917717;0.397234;-0.000001;,
  -0.999615;-0.027751;-0.000001;,
  0.776656;0.061912;-0.626876;,
  0.740086;0.053560;0.670377;,
  0.430219;0.061614;0.900619;,
  -0.740173;0.053560;0.670280;,
  -0.776698;0.061905;0.626824;,
  0.978124;0.208024;0.000004;,
  0.843486;0.255756;0.472356;,
  -0.978118;0.208051;0.000004;,
  -0.843485;0.255772;0.472350;,
  0.646148;0.059530;0.760887;,
  -0.646202;0.059533;0.760841;,
  0.547920;0.158153;0.821445;,
  -0.547941;0.158157;0.821430;,
  0.383721;-0.556921;-0.736612;,
  0.551624;-0.730543;-0.402514;,
  0.551623;-0.730542;0.402518;,
  0.383712;-0.556910;0.736625;,
  -0.383714;-0.556911;0.736623;,
  -0.551623;-0.730543;0.402517;,
  -0.551624;-0.730544;-0.402513;,
  -0.383723;-0.556922;-0.736610;,
  0.148821;-0.967071;-0.206459;,
  0.236697;-0.968469;-0.077736;,
  0.233893;-0.969317;0.075622;,
  0.144163;-0.969377;0.198810;,
  -0.000723;-0.968601;0.248621;,
  -0.149968;-0.967257;0.204752;,
  -0.246948;-0.965777;0.079319;,
  -0.250026;-0.964792;-0.081630;,
  -0.154965;-0.964728;-0.212803;,
  -0.000789;-0.965637;-0.259895;,
  -0.393852;-0.352541;-0.848879;,
  -0.923806;-0.382861;-0.000001;,
  -0.393839;-0.352549;0.848882;,
  0.393839;-0.352548;0.848882;,
  0.923806;-0.382860;-0.000001;,
  0.393852;-0.352540;-0.848879;;
  106;
  4;0,1,4,3;,
  4;2,21,22,5;,
  4;3,4,7,6;,
  4;5,22,23,8;,
  4;6,7,10,9;,
  4;8,23,24,11;,
  4;9,10,13,12;,
  4;11,24,25,14;,
  4;12,13,16,15;,
  4;14,25,26,17;,
  4;15,16,19,18;,
  4;17,26,27,20;,
  4;93,34,34,93;,
  4;94,95,39,26;,
  4;26,39,42,42;,
  4;34,35,37,34;,
  4;36,45,46,38;,
  4;95,37,40,39;,
  4;38,46,47,41;,
  4;39,40,43,96;,
  4;41,47,48,44;,
  4;45,97,97,97;,
  4;98,98,15,47;,
  4;47,15,99,99;,
  3;0,49,1;,
  3;2,100,21;,
  3;28,101,102;,
  3;103,29,104;,
  3;105,23,106;,
  3;6,107,108;,
  4;101,28,30,109;,
  4;110,31,29,103;,
  4;109,30,32,111;,
  4;111,32,35,106;,
  4;31,110,112,33;,
  4;33,112,108,36;,
  4;50,51,51,58;,
  4;51,52,52,51;,
  4;52,53,59,52;,
  4;54,55,55,60;,
  4;55,56,56,55;,
  4;56,57,61,56;,
  4;113,114,64,63;,
  4;114,115,65,64;,
  4;115,116,66,65;,
  4;117,118,69,68;,
  4;118,119,70,69;,
  4;119,120,71,70;,
  4;62,63,73,72;,
  4;63,64,74,73;,
  4;64,65,75,74;,
  4;65,66,76,75;,
  4;66,67,77,76;,
  4;67,68,78,77;,
  4;68,69,79,78;,
  4;69,70,80,79;,
  4;70,71,81,80;,
  4;71,62,72,81;,
  4;72,73,83,82;,
  4;73,74,84,83;,
  4;74,75,85,84;,
  4;75,76,86,85;,
  4;76,77,87,86;,
  4;77,78,88,87;,
  4;78,79,89,88;,
  4;79,80,90,89;,
  4;80,81,91,90;,
  4;81,72,82,91;,
  3;121,122,92;,
  3;92,122,123;,
  3;92,123,124;,
  3;92,124,125;,
  3;92,125,126;,
  3;92,127,128;,
  3;92,126,127;,
  3;92,128,129;,
  3;92,129,130;,
  3;92,130,121;,
  4;18,19,57,131;,
  4;99,99,132,132;,
  4;44,48,133,54;,
  4;96,43,53,134;,
  4;42,42,135,135;,
  4;20,27,136,50;,
  3;2,1,49;,
  3;102,29,28;,
  4;28,29,31,30;,
  4;30,31,33,32;,
  4;32,33,36,35;,
  4;35,36,38,37;,
  4;37,38,41,40;,
  4;40,41,44,43;,
  4;43,44,54,53;,
  4;53,54,60,59;,
  4;59,60,68,67;,
  3;59,67,66;,
  3;61,62,71;,
  4;61,58,63,62;,
  4;57,50,58,61;,
  4;19,20,50,57;,
  4;16,17,20,19;,
  4;1,2,5,4;,
  4;4,5,8,7;,
  4;7,8,11,10;,
  4;10,11,14,13;,
  4;13,14,17,16;;
 }
 MeshTextureCoords {
  117;
  0.000000;0.000000;,
  0.250000;0.000000;,
  0.250000;0.100000;,
  0.000000;0.100000;,
  0.750000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.100000;,
  0.750000;0.100000;,
  0.250000;0.200000;,
  0.000000;0.200000;,
  1.000000;0.200000;,
  0.750000;0.200000;,
  0.250000;0.300000;,
  0.000000;0.300000;,
  1.000000;0.300000;,
  0.750000;0.300000;,
  0.250000;0.400000;,
  0.000000;0.400000;,
  1.000000;0.400000;,
  0.750000;0.400000;,
  0.250000;0.500000;,
  0.000000;0.500000;,
  1.000000;0.500000;,
  0.750000;0.500000;,
  0.250000;0.600000;,
  0.000000;0.600000;,
  1.000000;0.600000;,
  0.750000;0.600000;,
  0.000000;0.300000;,
  1.000000;0.300000;,
  1.000000;0.400000;,
  0.000000;0.400000;,
  1.000000;0.500000;,
  0.000000;0.500000;,
  1.000000;0.600000;,
  0.000000;0.600000;,
  0.000000;0.300000;,
  0.250000;0.300000;,
  0.250000;0.400000;,
  0.000000;0.400000;,
  0.750000;0.300000;,
  1.000000;0.300000;,
  1.000000;0.400000;,
  0.750000;0.400000;,
  0.250000;0.500000;,
  0.000000;0.500000;,
  1.000000;0.500000;,
  0.750000;0.500000;,
  0.250000;0.600000;,
  0.000000;0.600000;,
  1.000000;0.600000;,
  0.750000;0.600000;,
  0.000000;0.300000;,
  1.000000;0.300000;,
  1.000000;0.400000;,
  0.000000;0.400000;,
  1.000000;0.500000;,
  0.000000;0.500000;,
  1.000000;0.600000;,
  0.000000;0.600000;,
  0.000000;0.000000;,
  0.250000;0.000000;,
  0.750000;0.000000;,
  0.250000;0.100000;,
  0.750000;0.100000;,
  0.250000;0.200000;,
  0.750000;0.200000;,
  0.100000;0.000000;,
  0.200000;0.000000;,
  0.200000;0.166670;,
  0.100000;0.166670;,
  0.300000;0.000000;,
  0.300000;0.166670;,
  0.400000;0.000000;,
  0.400000;0.166670;,
  0.600000;0.000000;,
  0.700000;0.000000;,
  0.700000;0.166670;,
  0.600000;0.166670;,
  0.800000;0.000000;,
  0.800000;0.166670;,
  0.900000;0.000000;,
  0.900000;0.166670;,
  0.200000;0.333330;,
  0.100000;0.333330;,
  0.300000;0.333330;,
  0.400000;0.333330;,
  0.700000;0.333330;,
  0.600000;0.333330;,
  0.800000;0.333330;,
  0.900000;0.333330;,
  0.000000;0.333330;,
  0.100000;0.500000;,
  0.000000;0.500000;,
  0.200000;0.500000;,
  0.300000;0.500000;,
  0.400000;0.500000;,
  0.500000;0.333330;,
  0.500000;0.500000;,
  0.600000;0.500000;,
  0.700000;0.500000;,
  0.800000;0.500000;,
  0.900000;0.500000;,
  1.000000;0.333330;,
  1.000000;0.500000;,
  0.100000;0.666670;,
  0.000000;0.666670;,
  0.200000;0.666670;,
  0.300000;0.666670;,
  0.400000;0.666670;,
  0.500000;0.666670;,
  0.600000;0.666670;,
  0.700000;0.666670;,
  0.800000;0.666670;,
  0.900000;0.666670;,
  1.000000;0.666670;,
  0.000000;0.000000;;
 }
}