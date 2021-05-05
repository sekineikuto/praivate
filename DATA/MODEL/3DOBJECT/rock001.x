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
 42;
 1.07282;-2.01842;-0.52606;,
 -12.31578;-2.00303;-10.15122;,
 6.13306;-2.01842;-16.10039;,
 -23.82340;-1.76363;-16.90180;,
 -27.72298;-1.76989;-0.52606;,
 17.87362;-2.01842;-0.52606;,
 6.13306;-2.01842;15.04809;,
 -12.17545;-2.01842;9.09920;,
 -32.00465;7.60816;-10.19052;,
 7.35693;1.18170;-25.71612;,
 -7.08952;-1.97845;-25.69126;,
 3.70113;10.04853;-29.57807;,
 28.73707;-3.37152;0.28834;,
 19.19287;3.41704;-15.44197;,
 25.42876;12.16898;-10.18522;,
 9.68187;-2.01842;25.97040;,
 22.07617;-3.60318;16.51892;,
 17.49772;5.76904;23.49697;,
 -21.46647;-2.01842;15.84952;,
 -7.11521;-2.01842;24.67342;,
 -17.23590;7.79839;24.67376;,
 -17.83742;8.70416;-25.04632;,
 16.58600;15.19306;-23.37681;,
 29.21646;3.93163;10.91045;,
 -2.46425;6.38503;30.86209;,
 -29.27901;7.47445;9.03757;,
 -0.79790;21.03299;-26.38473;,
 -20.53314;23.05588;-16.46225;,
 1.44789;28.63738;-22.05932;,
 25.44965;23.93192;-16.72649;,
 16.41267;25.06452;-23.83918;,
 16.66944;30.91578;-13.12794;,
 21.39985;18.36067;12.04748;,
 29.38607;23.49025;-0.54798;,
 12.30511;30.72266;8.79386;,
 -11.95332;19.98488;27.50552;,
 -2.23486;19.50059;26.08590;,
 -6.47816;31.32879;16.69932;,
 -23.68819;19.36647;-0.60479;,
 -20.56048;23.92210;14.98046;,
 -15.78957;31.66959;-4.35909;,
 0.11455;29.60490;-11.98578;;
 
 80;
 3;0,1,2;,
 3;3,1,4;,
 3;0,2,5;,
 3;0,5,6;,
 3;0,6,7;,
 3;3,4,8;,
 3;9,10,11;,
 3;12,13,14;,
 3;15,16,17;,
 3;18,19,20;,
 3;3,8,21;,
 3;9,11,22;,
 3;12,14,23;,
 3;15,17,24;,
 3;18,20,25;,
 3;26,27,28;,
 3;29,30,31;,
 3;32,33,34;,
 3;35,36,37;,
 3;38,39,40;,
 3;2,10,9;,
 3;2,1,10;,
 3;1,3,10;,
 3;4,7,18;,
 3;4,1,7;,
 3;1,0,7;,
 3;5,13,12;,
 3;5,2,13;,
 3;2,9,13;,
 3;6,16,15;,
 3;6,5,16;,
 3;5,12,16;,
 3;7,19,18;,
 3;7,6,19;,
 3;6,15,19;,
 3;8,25,38;,
 3;8,4,25;,
 3;4,18,25;,
 3;11,21,26;,
 3;11,10,21;,
 3;10,3,21;,
 3;14,22,29;,
 3;14,13,22;,
 3;13,9,22;,
 3;17,23,32;,
 3;17,16,23;,
 3;16,12,23;,
 3;20,24,35;,
 3;20,19,24;,
 3;19,15,24;,
 3;21,27,26;,
 3;21,8,27;,
 3;8,38,27;,
 3;22,30,29;,
 3;22,11,30;,
 3;11,26,30;,
 3;23,33,32;,
 3;23,14,33;,
 3;14,29,33;,
 3;24,36,35;,
 3;24,17,36;,
 3;17,32,36;,
 3;25,39,38;,
 3;25,20,39;,
 3;20,35,39;,
 3;28,40,41;,
 3;28,27,40;,
 3;27,38,40;,
 3;31,28,41;,
 3;31,30,28;,
 3;30,26,28;,
 3;34,31,41;,
 3;34,33,31;,
 3;33,29,31;,
 3;37,34,41;,
 3;37,36,34;,
 3;36,32,34;,
 3;40,37,41;,
 3;40,39,37;,
 3;39,35,37;;
 
 MeshMaterialList {
  11;
  80;
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5;;
  Material {
   0.221600;0.357600;0.058400;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.178400;0.178400;0.015200;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.512000;0.512000;0.512000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.047059;0.000000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.062745;0.000000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.090980;0.000000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.165600;0.257600;0.015200;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.032000;0.035200;0.017600;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.033600;0.051200;0.003200;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.488800;0.467200;0.512000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.036800;0.025600;0.008800;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  54;
  -0.000302;-1.000000;-0.000220;,
  -0.490897;-0.761911;-0.422507;,
  0.408664;-0.608831;-0.679940;,
  0.962721;-0.229218;-0.143624;,
  0.295166;-0.327565;0.897540;,
  -0.715764;-0.395890;0.575285;,
  -0.171851;0.400726;-0.899937;,
  0.774666;0.422603;-0.470425;,
  0.590366;0.465621;0.659292;,
  -0.301537;0.425018;0.853484;,
  -0.850369;0.525709;0.022409;,
  0.008836;0.998274;-0.058053;,
  0.165137;-0.976187;-0.140675;,
  -0.008871;-0.999957;-0.002620;,
  -0.039614;-0.875141;-0.482244;,
  -0.384436;-0.922856;0.023348;,
  -0.004128;-0.999989;-0.002226;,
  0.013549;-0.991263;-0.131202;,
  0.654678;-0.550494;-0.518029;,
  -0.032416;-0.999456;-0.006091;,
  0.710997;-0.341063;0.614946;,
  -0.309189;-0.489736;0.815206;,
  -0.940637;-0.032905;-0.337814;,
  -0.941361;0.035750;0.335501;,
  0.119005;-0.039600;-0.992104;,
  -0.472113;0.039696;-0.880644;,
  0.902862;-0.156611;-0.400391;,
  0.637719;-0.185788;-0.747527;,
  0.554533;0.116524;0.823963;,
  0.934631;-0.003110;0.355604;,
  -0.633621;-0.129439;0.762739;,
  -0.001063;-0.076275;0.997086;,
  -0.627023;0.585144;-0.514246;,
  0.326897;0.448823;-0.831683;,
  0.627674;0.711204;0.316567;,
  0.315114;0.510313;0.800177;,
  -0.761511;0.537066;0.362851;,
  -0.090048;0.858166;-0.505413;,
  -0.534725;0.842237;-0.068603;,
  0.257013;0.948023;-0.187607;,
  0.316282;0.869332;0.379774;,
  -0.065226;0.916136;0.395526;,
  -0.004315;-0.999973;-0.005939;,
  -0.090139;-0.933145;-0.348017;,
  -0.105561;-0.972486;-0.207670;,
  -0.104425;-0.993980;-0.033155;,
  -0.051015;-0.998560;0.016575;,
  0.000000;-1.000000;-0.000000;,
  -0.855148;0.503157;0.124718;,
  -0.946062;-0.295854;0.132050;,
  -0.195648;-0.138229;-0.970883;,
  0.750538;-0.322180;-0.576968;,
  0.962605;-0.138052;-0.233096;,
  0.088774;0.992539;-0.083578;;
  80;
  3;0,13,12;,
  3;1,13,15;,
  3;0,12,17;,
  3;0,17,19;,
  3;0,19,16;,
  3;1,15,22;,
  3;2,14,24;,
  3;3,18,26;,
  3;4,20,28;,
  3;5,21,30;,
  3;1,22,25;,
  3;2,24,27;,
  3;3,26,29;,
  3;4,28,31;,
  3;5,30,23;,
  3;6,32,37;,
  3;7,33,39;,
  3;8,34,40;,
  3;9,35,41;,
  3;10,36,38;,
  3;12,14,2;,
  3;12,13,14;,
  3;13,1,14;,
  3;15,16,42;,
  3;15,13,16;,
  3;13,0,16;,
  3;17,43,44;,
  3;17,12,18;,
  3;12,2,18;,
  3;19,45,46;,
  3;19,17,45;,
  3;17,44,45;,
  3;16,47,42;,
  3;16,19,47;,
  3;19,46,47;,
  3;48,23,10;,
  3;22,49,23;,
  3;15,5,23;,
  3;24,25,6;,
  3;24,50,25;,
  3;14,1,25;,
  3;26,27,51;,
  3;26,18,27;,
  3;18,2,27;,
  3;28,29,8;,
  3;28,20,29;,
  3;20,3,29;,
  3;30,31,9;,
  3;30,21,31;,
  3;21,4,31;,
  3;25,32,6;,
  3;25,22,32;,
  3;22,10,32;,
  3;27,33,7;,
  3;27,24,33;,
  3;24,6,33;,
  3;29,34,8;,
  3;29,26,52;,
  3;26,7,52;,
  3;31,35,9;,
  3;31,28,35;,
  3;28,8,35;,
  3;23,36,10;,
  3;23,30,36;,
  3;30,9,36;,
  3;37,53,11;,
  3;37,32,38;,
  3;32,10,38;,
  3;39,37,11;,
  3;39,33,37;,
  3;33,6,37;,
  3;40,39,11;,
  3;40,34,39;,
  3;34,7,39;,
  3;41,40,11;,
  3;41,35,40;,
  3;35,8,40;,
  3;38,41,11;,
  3;38,36,41;,
  3;36,9,41;;
 }
 MeshTextureCoords {
  42;
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;;
 }
}
