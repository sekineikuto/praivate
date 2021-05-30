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
 103;
 -0.19436;122.01577;-11.49060;,
 11.27643;122.01577;-6.73925;,
 11.27643;0.34211;-6.73926;,
 -0.19436;0.34211;-11.49061;,
 16.02779;122.01577;4.73154;,
 16.02779;0.34211;4.73153;,
 11.27643;122.01577;16.20234;,
 11.27643;0.34211;16.20233;,
 -0.19436;122.01577;20.95368;,
 -0.19436;0.34211;20.95367;,
 -11.66516;122.01577;16.20234;,
 -11.66516;0.34211;16.20233;,
 -16.41651;122.01577;4.73154;,
 -16.41651;0.34211;4.73153;,
 -11.66516;122.01577;-6.73925;,
 -11.66516;0.34211;-6.73926;,
 6.26953;-121.33159;-1.73241;,
 -0.19436;-121.33159;-4.40984;,
 8.94699;-121.33159;4.73151;,
 6.26953;-121.33159;11.19541;,
 -0.19436;-121.33159;13.87286;,
 -6.65829;-121.33159;11.19541;,
 -0.19436;-121.33159;13.87286;,
 -9.33571;-121.33159;4.73151;,
 -6.65829;-121.33159;-1.73241;,
 -0.19436;247.38804;4.73156;,
 -0.19436;-246.70381;4.73149;,
 -0.19436;-121.33159;-4.40984;,
 6.26953;-121.33159;-1.73241;,
 8.94699;-121.33159;4.73151;,
 6.26953;-121.33159;11.19541;,
 -0.19436;-121.33159;13.87286;,
 -6.65829;-121.33159;11.19541;,
 -9.33571;-121.33159;4.73151;,
 -6.65829;-121.33159;-1.73241;,
 -3.01908;-219.23008;-115.83898;,
 -61.79470;-66.60583;-78.19456;,
 -40.87625;9.00295;-75.02799;,
 5.68768;-50.32495;-102.72243;,
 5.68768;-50.32495;-102.72243;,
 -40.87625;9.00295;-75.02799;,
 -61.79470;-66.60583;-78.19456;,
 -3.01908;-219.23008;-115.83898;,
 -61.79470;-66.60583;-78.19456;,
 -66.81194;57.76060;-35.05981;,
 -42.70158;57.76060;-43.49587;,
 -40.87625;9.00295;-75.02799;,
 -66.81194;57.76060;-35.05981;,
 -45.30908;119.56915;-1.93949;,
 -27.49218;119.56915;-18.07472;,
 -42.70158;57.76060;-43.49587;,
 -45.30908;119.56915;-1.93949;,
 -4.67379;143.39829;10.65105;,
 -3.24278;143.39829;-2.96411;,
 -27.49218;119.56915;-18.07472;,
 -118.06111;-219.23008;14.14448;,
 -74.47938;-66.60585;68.66327;,
 -73.51670;9.00294;47.52844;,
 -105.92675;-50.32496;4.11441;,
 -74.47938;-66.60585;68.66327;,
 -31.05643;57.76060;69.14419;,
 -41.96647;57.76060;46.04771;,
 -73.51670;9.00294;47.52844;,
 -31.05643;57.76060;69.14419;,
 -0.36521;119.56915;44.29713;,
 -18.27439;119.56915;28.26442;,
 -41.96647;57.76060;46.04771;,
 -0.36521;119.56915;44.29713;,
 7.90879;143.39829;2.56841;,
 -5.78139;143.39829;2.56838;,
 -18.27439;119.56915;28.26442;,
 -7.95197;-219.23008;124.27201;,
 53.88103;-66.60587;91.89350;,
 33.31815;9.00293;86.91574;,
 -15.48241;-50.32498;110.44663;,
 53.88103;-66.60587;91.89350;,
 62.63863;57.76060;49.36002;,
 37.88468;57.76060;55.66265;,
 33.31815;9.00293;86.91574;,
 62.63863;57.76060;49.36002;,
 44.10415;119.56915;14.49165;,
 24.94873;119.56915;29.01266;,
 37.88468;57.76060;55.66265;,
 44.10415;119.56915;14.49165;,
 4.72076;143.39829;-1.59256;,
 2.10852;143.39829;11.84606;,
 24.94873;119.56915;29.01266;,
 118.83045;-219.23008;-10.35272;,
 75.24847;-66.60585;-64.87147;,
 74.28584;9.00295;-43.73657;,
 106.69583;-50.32496;-0.32255;,
 75.24847;-66.60585;-64.87147;,
 31.82560;57.76060;-65.35233;,
 42.73568;57.76060;-42.25581;,
 74.28584;9.00295;-43.73657;,
 31.82560;57.76060;-65.35233;,
 1.13438;119.56915;-40.50530;,
 19.04358;119.56915;-24.47254;,
 42.73568;57.76060;-42.25581;,
 1.13438;119.56915;-40.50530;,
 -7.13963;143.39829;1.22351;,
 6.55053;143.39829;1.22351;,
 19.04358;119.56915;-24.47254;;
 
 64;
 4;0,1,2,3;,
 4;1,4,5,2;,
 4;4,6,7,5;,
 4;6,8,9,7;,
 4;8,10,11,9;,
 4;10,12,13,11;,
 4;12,14,15,13;,
 4;14,0,3,15;,
 4;3,2,16,17;,
 4;2,5,18,16;,
 4;5,7,19,18;,
 4;7,9,20,19;,
 4;9,11,21,22;,
 4;11,13,23,21;,
 4;13,15,24,23;,
 4;15,3,17,24;,
 3;25,1,0;,
 3;25,4,1;,
 3;25,6,4;,
 3;25,8,6;,
 3;25,10,8;,
 3;25,12,10;,
 3;25,14,12;,
 3;25,0,14;,
 3;26,27,28;,
 3;26,28,29;,
 3;26,29,30;,
 3;26,30,31;,
 3;26,31,32;,
 3;26,32,33;,
 3;26,33,34;,
 3;26,34,27;,
 4;35,36,37,38;,
 4;39,40,41,42;,
 4;43,44,45,46;,
 4;46,45,44,43;,
 4;47,48,49,50;,
 4;50,49,48,47;,
 4;51,52,53,54;,
 4;54,53,52,51;,
 4;55,56,57,58;,
 4;58,57,56,55;,
 4;59,60,61,62;,
 4;62,61,60,59;,
 4;63,64,65,66;,
 4;66,65,64,63;,
 4;67,68,69,70;,
 4;70,69,68,67;,
 4;71,72,73,74;,
 4;74,73,72,71;,
 4;75,76,77,78;,
 4;78,77,76,75;,
 4;79,80,81,82;,
 4;82,81,80,79;,
 4;83,84,85,86;,
 4;86,85,84,83;,
 4;87,88,89,90;,
 4;90,89,88,87;,
 4;91,92,93,94;,
 4;94,93,92,91;,
 4;95,96,97,98;,
 4;98,97,96,95;,
 4;99,100,101,102;,
 4;102,101,100,99;;
 
 MeshMaterialList {
  10;
  64;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  5,
  5,
  4,
  4,
  3,
  3,
  2,
  2,
  5,
  5,
  4,
  4,
  3,
  3,
  2,
  2,
  5,
  5,
  4,
  4,
  3,
  3,
  2,
  2,
  4,
  5,
  4,
  4,
  3,
  3,
  2,
  2;;
  Material {
   0.000000;0.132000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.165000;1.000000;;
  }
  Material {
   0.000000;0.103200;0.633600;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.129000;0.792000;;
  }
  Material {
   0.000000;0.062400;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.076440;0.980000;;
  }
  Material {
   0.000000;0.044000;0.542400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.033000;0.406800;;
  }
  Material {
   0.000000;0.028000;0.320000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.021000;0.240000;;
  }
  Material {
   0.000000;0.009600;0.128800;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.007200;0.096600;;
  }
  Material {
   1.000000;0.835000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   1.000000;0.835000;0.000000;;
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.376800;0.000000;1.000000;;
   5.000000;
   1.000000;1.000000;1.000000;;
   1.000000;0.471000;0.000000;;
  }
  Material {
   1.000000;1.000000;1.000000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  64;
  0.701261;0.128322;-0.701261;,
  0.000000;0.064333;-0.997929;,
  0.705642;0.064333;-0.705642;,
  0.997929;0.064333;-0.000000;,
  0.705642;0.064333;0.705642;,
  0.000000;0.064333;0.997929;,
  -0.705642;0.064333;0.705642;,
  -0.997929;0.064333;-0.000000;,
  -0.705642;0.064333;-0.705642;,
  0.000000;-0.029064;-0.999578;,
  0.706808;-0.029064;-0.706808;,
  0.999578;-0.029064;0.000000;,
  0.706808;-0.029064;0.706808;,
  0.000000;-0.029064;0.999578;,
  -0.706808;-0.029064;0.706808;,
  -0.999578;-0.029064;0.000000;,
  -0.706808;-0.029064;-0.706808;,
  0.000001;-0.065411;-0.997858;,
  0.705592;-0.065411;-0.705593;,
  0.997858;-0.065411;0.000000;,
  0.705592;-0.065411;0.705593;,
  0.000001;-0.065411;0.997858;,
  -0.705593;-0.065411;0.705592;,
  -0.997858;-0.065411;0.000000;,
  -0.705593;-0.065411;-0.705592;,
  0.705234;-0.072720;-0.705235;,
  0.701260;0.128322;0.701261;,
  -0.701260;0.128322;0.701261;,
  -0.701261;0.128322;-0.701261;,
  0.705234;-0.072721;0.705235;,
  -0.705235;-0.072721;0.705234;,
  -0.705235;-0.072721;-0.705234;,
  -0.363817;0.115512;-0.924280;,
  -0.496130;0.377164;-0.782050;,
  -0.451708;0.484587;-0.749090;,
  -0.478836;0.833442;-0.275846;,
  0.363817;-0.115512;0.924280;,
  0.496130;-0.377164;0.782050;,
  0.451708;-0.484587;0.749090;,
  0.478836;-0.833442;0.275846;,
  -0.881187;0.115512;0.458438;,
  -0.725906;0.377165;0.575158;,
  -0.697770;0.484587;0.527534;,
  -0.224284;0.833441;0.505046;,
  0.881187;-0.115512;-0.458438;,
  0.725906;-0.377165;-0.575158;,
  0.697770;-0.484587;-0.527534;,
  0.224284;-0.833441;-0.505046;,
  0.281877;0.115513;0.952472;,
  0.426082;0.377165;0.822314;,
  0.384702;0.484587;0.785608;,
  0.452971;0.833442;0.316530;,
  -0.281877;-0.115513;-0.952472;,
  -0.426082;-0.377165;-0.822314;,
  -0.384702;-0.484587;-0.785608;,
  -0.452971;-0.833442;-0.316530;,
  0.881188;0.115513;-0.458438;,
  0.725906;0.377165;-0.575158;,
  0.697770;0.484587;-0.527534;,
  0.224284;0.833442;-0.505046;,
  -0.881188;-0.115513;0.458438;,
  -0.725906;-0.377165;0.575158;,
  -0.697770;-0.484587;0.527534;,
  -0.224284;-0.833442;0.505046;;
  64;
  4;1,2,10,9;,
  4;2,3,11,10;,
  4;3,4,12,11;,
  4;4,5,13,12;,
  4;5,6,14,13;,
  4;6,7,15,14;,
  4;7,8,16,15;,
  4;8,1,9,16;,
  4;9,10,18,17;,
  4;10,11,19,18;,
  4;11,12,20,19;,
  4;12,13,21,20;,
  4;13,14,22,21;,
  4;14,15,23,22;,
  4;15,16,24,23;,
  4;16,9,17,24;,
  3;0,2,1;,
  3;0,3,2;,
  3;26,4,3;,
  3;26,5,4;,
  3;27,6,5;,
  3;27,7,6;,
  3;28,8,7;,
  3;28,1,8;,
  3;25,17,18;,
  3;25,18,19;,
  3;29,19,20;,
  3;29,20,21;,
  3;30,21,22;,
  3;30,22,23;,
  3;31,23,24;,
  3;31,24,17;,
  4;32,32,32,32;,
  4;36,36,36,36;,
  4;33,33,33,33;,
  4;37,37,37,37;,
  4;34,34,34,34;,
  4;38,38,38,38;,
  4;35,35,35,35;,
  4;39,39,39,39;,
  4;40,40,40,40;,
  4;44,44,44,44;,
  4;41,41,41,41;,
  4;45,45,45,45;,
  4;42,42,42,42;,
  4;46,46,46,46;,
  4;43,43,43,43;,
  4;47,47,47,47;,
  4;48,48,48,48;,
  4;52,52,52,52;,
  4;49,49,49,49;,
  4;53,53,53,53;,
  4;50,50,50,50;,
  4;54,54,54,54;,
  4;51,51,51,51;,
  4;55,55,55,55;,
  4;56,56,56,56;,
  4;60,60,60,60;,
  4;57,57,57,57;,
  4;61,61,61,61;,
  4;58,58,58,58;,
  4;62,62,62,62;,
  4;59,59,59,59;,
  4;63,63,63,63;;
 }
 MeshTextureCoords {
  103;
  0.500250;0.459640;,
  0.485780;0.471620;,
  0.306950;0.260100;,
  0.507330;0.081860;,
  0.479850;0.500430;,
  0.290940;0.503320;,
  0.485780;0.529240;,
  0.306950;0.744690;,
  0.500250;0.541220;,
  0.507330;0.919790;,
  0.514710;0.529230;,
  0.694800;0.739940;,
  0.520640;0.500430;,
  0.709990;0.503250;,
  0.514710;0.471630;,
  0.694800;0.264840;,
  0.008490;0.482990;,
  0.999740;0.475740;,
  0.012100;0.500470;,
  0.008490;0.517940;,
  -0.000260;0.525190;,
  0.990990;0.517940;,
  0.999740;0.525190;,
  0.987380;0.500470;,
  0.990990;0.482990;,
  0.500120;0.500220;,
  0.506534;0.993891;,
  0.992990;0.988425;,
  0.207093;0.982952;,
  0.327421;0.973509;,
  0.418752;0.966462;,
  0.502230;0.963759;,
  0.585393;0.965958;,
  0.675342;0.972610;,
  0.790512;0.981970;,
  0.995853;0.845225;,
  0.893561;0.687527;,
  0.920605;0.466583;,
  1.008803;0.644812;,
  0.008803;0.644812;,
  -0.079395;0.466583;,
  -0.106439;0.687527;,
  -0.004147;0.845225;,
  0.893561;0.687527;,
  0.826912;0.292028;,
  0.876467;0.258559;,
  0.920605;0.466583;,
  0.826912;0.292028;,
  0.756809;0.115394;,
  0.842564;0.085473;,
  0.876467;0.258559;,
  0.756809;0.115394;,
  0.565812;0.025762;,
  0.867859;0.009749;,
  0.842564;0.085473;,
  0.731023;0.841809;,
  0.631463;0.685140;,
  0.658659;0.467379;,
  0.743821;0.641085;,
  0.631463;0.685140;,
  0.567187;0.292731;,
  0.617625;0.262035;,
  0.658659;0.467379;,
  0.567187;0.292731;,
  0.501312;0.112939;,
  0.591347;0.087341;,
  0.617625;0.262035;,
  0.501312;0.112939;,
  0.299976;0.018438;,
  0.683464;0.014034;,
  0.591347;0.087341;,
  0.510170;0.835571;,
  0.415598;0.677867;,
  0.441740;0.469309;,
  0.522166;0.634926;,
  0.415598;0.677867;,
  0.356218;0.300473;,
  0.404890;0.274308;,
  0.441740;0.469309;,
  0.356218;0.300473;,
  0.300526;0.117885;,
  0.386964;0.098587;,
  0.404890;0.274308;,
  0.300526;0.117885;,
  0.198217;0.011055;,
  0.471965;0.026646;,
  0.386964;0.098587;,
  0.236169;0.841388;,
  0.136765;0.687990;,
  0.165311;0.466877;,
  0.249519;0.640287;,
  0.136765;0.687990;,
  0.072126;0.286271;,
  0.125899;0.256315;,
  0.165311;0.466877;,
  0.072126;0.286271;,
  0.004456;0.104007;,
  0.105246;0.080771;,
  0.125899;0.256315;,
  0.004456;0.104007;,
  -0.277012;0.016066;,
  0.279388;0.014781;,
  0.105246;0.080771;;
 }
}