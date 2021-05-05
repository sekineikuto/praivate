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
 130;
 -0.00782;4.32091;0.00862;,
 -1.02118;3.99615;1.78984;,
 -0.00782;3.99927;2.20832;,
 -0.00782;4.32091;0.00862;,
 -1.64747;3.98781;0.69424;,
 -0.00782;4.32091;0.00862;,
 -1.64747;3.97756;-0.66000;,
 -0.00782;4.32091;0.00862;,
 -1.02118;3.96925;-1.75559;,
 -0.00782;4.32091;0.00862;,
 -0.00782;3.96606;-2.17407;,
 -0.00782;4.32091;0.00862;,
 1.00556;3.96925;-1.75559;,
 -0.00782;4.32091;0.00862;,
 1.63185;3.97756;-0.66000;,
 -0.00782;4.32091;0.00862;,
 1.63185;3.98781;0.69424;,
 -0.00782;4.32091;0.00862;,
 1.00556;3.99615;1.78984;,
 -0.00782;4.32091;0.00862;,
 -0.00782;3.99927;2.20832;,
 -1.93537;2.64059;3.43395;,
 -0.00782;2.65113;4.22972;,
 -3.12665;2.61304;1.35062;,
 -3.12665;2.57900;-1.22452;,
 -1.93537;2.55766;-2.84107;,
 -0.00782;2.55098;-3.34650;,
 1.91974;2.55766;-2.84107;,
 3.11103;2.57900;-1.22452;,
 3.11103;2.61304;1.35063;,
 1.91974;2.64059;3.43395;,
 -0.00782;2.65113;4.22972;,
 -2.66084;4.51880;4.64555;,
 -0.00782;4.52714;5.74115;,
 -4.30055;4.49710;1.77724;,
 -4.30055;1.23623;-1.68076;,
 -2.66084;1.21064;-3.61855;,
 -0.00782;1.20146;-4.31424;,
 2.64522;1.21064;-3.61855;,
 4.28493;1.23623;-1.68076;,
 4.28493;4.49710;1.77724;,
 2.64522;4.51880;4.64555;,
 -0.00782;4.52714;5.74115;,
 -3.12665;1.28636;5.54665;,
 -0.00782;1.30337;6.83420;,
 -5.05421;1.24176;2.17574;,
 -5.05421;-0.45174;-1.95614;,
 -3.12665;-0.48009;-4.10020;,
 -0.00782;-0.49090;-4.91801;,
 3.11103;-0.48009;-4.10019;,
 5.03859;-0.45174;-1.95614;,
 5.03859;1.24176;2.17574;,
 3.11103;1.28636;5.54665;,
 -0.00782;1.30337;6.83420;,
 -3.25463;-1.68043;5.72130;,
 -0.00782;-1.66310;7.03521;,
 -5.26124;-1.72591;2.28140;,
 -5.26124;-1.78211;-1.97054;,
 -3.25463;-1.81078;-4.14284;,
 -0.00782;-1.82180;-4.97739;,
 3.23901;-1.81078;-4.14284;,
 5.24563;-1.78211;-1.97054;,
 5.24563;-1.72591;2.28141;,
 3.23901;-1.68043;5.72130;,
 -0.00782;-1.66310;7.03521;,
 -3.41960;-2.80508;6.08674;,
 -0.00782;-2.78664;7.48125;,
 -5.52823;-2.85327;2.43581;,
 -5.52823;-2.91294;-2.07699;,
 -3.41960;-2.94278;-4.33574;,
 -0.00782;-2.95450;-5.22151;,
 3.40399;-2.94278;-4.33574;,
 5.51260;-2.91294;-2.07699;,
 5.51260;-2.85327;2.43581;,
 3.40399;-2.80508;6.08675;,
 -0.00782;-2.78664;7.48125;,
 -2.66084;-5.46555;4.90797;,
 -0.00782;-5.45247;6.00358;,
 -4.30055;-5.49981;2.03967;,
 -4.30055;-5.54210;-1.50576;,
 -2.66084;-5.56524;-3.44413;,
 -0.00782;-5.57354;-4.14002;,
 2.64522;-5.56524;-3.44413;,
 4.28493;-5.54210;-1.50576;,
 4.28493;-5.49981;2.03967;,
 2.64522;-5.46555;4.90798;,
 -0.00782;-5.45247;6.00358;,
 -0.00782;-15.41557;6.12445;,
 -2.66084;-15.42867;5.02886;,
 -1.93537;-11.55810;3.56890;,
 -0.00782;-11.52477;4.36412;,
 -4.30055;-15.46287;2.16053;,
 -3.12665;-11.64532;1.48704;,
 -4.30055;-15.50517;-1.38489;,
 -3.12665;-11.75312;-1.08630;,
 -2.66084;-15.52830;-3.32326;,
 -1.93537;-11.82082;-2.70171;,
 -0.00782;-15.53661;-4.01915;,
 -0.00782;-11.84198;-3.20679;,
 2.64522;-15.52830;-3.32326;,
 1.91974;-11.82082;-2.70171;,
 4.28493;-15.50517;-1.38489;,
 3.11103;-11.75312;-1.08630;,
 4.28493;-15.46287;2.16053;,
 3.11103;-11.64532;1.48705;,
 2.64522;-15.42867;5.02886;,
 1.91974;-11.55810;3.56890;,
 -0.00782;-15.41557;6.12445;,
 -0.00782;-11.52477;4.36412;,
 -1.02118;-12.93711;1.97553;,
 -0.00782;-12.91960;2.39360;,
 -1.64747;-12.98299;0.88103;,
 -1.64747;-13.03964;-0.47186;,
 -1.02118;-13.08553;-1.56636;,
 -0.00782;-13.10302;-1.98443;,
 1.00556;-13.08553;-1.56636;,
 1.63185;-13.03964;-0.47186;,
 1.63185;-12.98299;0.88103;,
 1.00556;-12.93711;1.97553;,
 -0.00782;-12.91960;2.39360;,
 -0.00782;-13.46342;0.20604;,
 -0.00782;-13.46342;0.20604;,
 -0.00782;-13.46342;0.20604;,
 -0.00782;-13.46342;0.20604;,
 -0.00782;-13.46342;0.20604;,
 -0.00782;-13.46342;0.20604;,
 -0.00782;-13.46342;0.20604;,
 -0.00782;-13.46342;0.20604;,
 -0.00782;-13.46342;0.20604;,
 -0.00782;-13.46342;0.20604;;
 
 110;
 3;0,1,2;,
 3;3,4,1;,
 3;5,6,4;,
 3;7,8,6;,
 3;9,10,8;,
 3;11,12,10;,
 3;13,14,12;,
 3;15,16,14;,
 3;17,18,16;,
 3;19,20,18;,
 4;2,1,21,22;,
 4;1,4,23,21;,
 4;4,6,24,23;,
 4;6,8,25,24;,
 4;8,10,26,25;,
 4;10,12,27,26;,
 4;12,14,28,27;,
 4;14,16,29,28;,
 4;16,18,30,29;,
 4;18,20,31,30;,
 4;22,21,32,33;,
 4;21,23,34,32;,
 4;23,24,35,34;,
 4;24,25,36,35;,
 4;25,26,37,36;,
 4;26,27,38,37;,
 4;27,28,39,38;,
 4;28,29,40,39;,
 4;29,30,41,40;,
 4;30,31,42,41;,
 4;33,32,43,44;,
 4;32,34,45,43;,
 4;34,35,46,45;,
 4;35,36,47,46;,
 4;36,37,48,47;,
 4;37,38,49,48;,
 4;38,39,50,49;,
 4;39,40,51,50;,
 4;40,41,52,51;,
 4;41,42,53,52;,
 4;44,43,54,55;,
 4;43,45,56,54;,
 4;45,46,57,56;,
 4;46,47,58,57;,
 4;47,48,59,58;,
 4;48,49,60,59;,
 4;49,50,61,60;,
 4;50,51,62,61;,
 4;51,52,63,62;,
 4;52,53,64,63;,
 4;55,54,65,66;,
 4;54,56,67,65;,
 4;56,57,68,67;,
 4;57,58,69,68;,
 4;58,59,70,69;,
 4;59,60,71,70;,
 4;60,61,72,71;,
 4;61,62,73,72;,
 4;62,63,74,73;,
 4;63,64,75,74;,
 4;66,65,76,77;,
 4;65,67,78,76;,
 4;67,68,79,78;,
 4;68,69,80,79;,
 4;69,70,81,80;,
 4;70,71,82,81;,
 4;71,72,83,82;,
 4;72,73,84,83;,
 4;73,74,85,84;,
 4;74,75,86,85;,
 4;87,88,89,90;,
 4;88,91,92,89;,
 4;91,93,94,92;,
 4;93,95,96,94;,
 4;95,97,98,96;,
 4;97,99,100,98;,
 4;99,101,102,100;,
 4;101,103,104,102;,
 4;103,105,106,104;,
 4;105,107,108,106;,
 4;90,89,109,110;,
 4;89,92,111,109;,
 4;92,94,112,111;,
 4;94,96,113,112;,
 4;96,98,114,113;,
 4;98,100,115,114;,
 4;100,102,116,115;,
 4;102,104,117,116;,
 4;104,106,118,117;,
 4;106,108,119,118;,
 3;110,109,120;,
 3;109,111,121;,
 3;111,112,122;,
 3;112,113,123;,
 3;113,114,124;,
 3;114,115,125;,
 3;115,116,126;,
 3;116,117,127;,
 3;117,118,128;,
 3;118,119,129;,
 4;76,88,87,77;,
 4;76,78,91,88;,
 4;78,79,93,91;,
 4;80,95,93,79;,
 4;80,81,97,95;,
 4;81,82,99,97;,
 4;82,83,101,99;,
 4;84,103,101,83;,
 4;84,85,105,103;,
 4;85,86,87,105;;
 
 MeshMaterialList {
  11;
  110;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0;;
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.664800;0.778400;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.640000;0.800000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.000000;0.225600;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.752800;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.310400;0.084800;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.125600;0.125600;0.125600;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.640000;0.176000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.037600;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.759200;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.000000;0.200800;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  117;
  -0.000001;0.999970;-0.007807;,
  -0.000001;0.934369;0.356307;,
  -0.265268;0.921723;0.282946;,
  -0.421814;0.901046;0.100945;,
  -0.426183;0.895111;-0.130938;,
  -0.278727;0.888031;-0.365668;,
  -0.000001;0.877839;-0.478956;,
  0.278726;0.888031;-0.365668;,
  0.426182;0.895111;-0.130938;,
  0.421813;0.901046;0.100945;,
  0.265267;0.921724;0.282947;,
  -0.000001;0.831525;0.555487;,
  -0.405075;0.802725;0.437660;,
  -0.634848;0.756637;0.156423;,
  -0.443406;0.818329;-0.365690;,
  -0.420109;0.665335;-0.617120;,
  -0.000001;0.622715;-0.782448;,
  0.420107;0.665336;-0.617121;,
  0.443406;0.818329;-0.365690;,
  0.634847;0.756637;0.156424;,
  0.405073;0.802725;0.437662;,
  0.000001;0.626714;-0.779249;,
  0.533097;0.593805;-0.602663;,
  0.513107;0.730944;-0.449935;,
  -0.575754;0.643740;-0.504090;,
  -0.455683;0.503306;-0.734191;,
  -0.000000;0.464373;-0.885639;,
  0.455682;0.503306;-0.734191;,
  0.575753;0.643740;-0.504090;,
  -0.513106;0.730944;-0.449936;,
  -0.533095;0.593806;-0.602664;,
  0.000000;0.198305;0.980140;,
  -0.649492;0.183430;0.737912;,
  -0.958303;0.198509;0.205548;,
  -0.887658;0.242935;-0.391210;,
  -0.504772;0.228317;-0.832512;,
  -0.000000;0.195630;-0.980678;,
  0.504771;0.228318;-0.832513;,
  0.887657;0.242938;-0.391211;,
  0.958302;0.198511;0.205548;,
  0.649491;0.183421;0.737915;,
  -0.000002;0.221098;0.975251;,
  -0.646181;0.199225;0.736722;,
  -0.951922;0.177765;0.249489;,
  -0.914435;0.179946;-0.362530;,
  -0.506968;0.151499;-0.848547;,
  -0.000000;0.129396;-0.991593;,
  0.506967;0.151500;-0.848547;,
  0.914435;0.179944;-0.362530;,
  0.951922;0.177762;0.249489;,
  0.646180;0.199226;0.736723;,
  -0.000003;-0.069706;0.997568;,
  -0.657655;-0.078487;0.749220;,
  -0.961428;-0.095915;0.257791;,
  -0.927368;-0.110395;-0.357493;,
  -0.513228;-0.101080;-0.852279;,
  -0.000001;-0.092202;-0.995740;,
  0.513228;-0.101081;-0.852279;,
  0.927368;-0.110399;-0.357492;,
  0.961428;-0.095919;0.257790;,
  0.657654;-0.078486;0.749220;,
  -0.000002;-0.248010;0.968758;,
  -0.641012;-0.235323;0.730566;,
  -0.941345;-0.223260;0.253031;,
  -0.912323;-0.231807;-0.337539;,
  -0.515371;-0.216800;-0.829090;,
  -0.000001;-0.201488;-0.979491;,
  0.515371;-0.216800;-0.829090;,
  0.912323;-0.231806;-0.337539;,
  0.941345;-0.223259;0.253030;,
  0.641011;-0.235324;0.730566;,
  0.000001;-0.413553;-0.910480;,
  0.618666;-0.377196;-0.689185;,
  0.916703;-0.323972;-0.233877;,
  0.899794;-0.295089;0.321394;,
  0.525564;-0.247775;0.813873;,
  0.000001;-0.214264;0.976776;,
  -0.525562;-0.247776;0.813874;,
  -0.899793;-0.295089;0.321394;,
  -0.916702;-0.323972;-0.233879;,
  -0.618664;-0.377197;-0.689186;,
  -0.000001;-0.909870;0.414893;,
  -0.274460;-0.899979;0.338687;,
  -0.436702;-0.887043;0.149821;,
  -0.441489;-0.892809;-0.089330;,
  -0.288672;-0.898713;-0.330127;,
  -0.000001;-0.894963;-0.446141;,
  0.288671;-0.898713;-0.330127;,
  0.441488;-0.892809;-0.089330;,
  0.436701;-0.887044;0.149821;,
  0.274458;-0.899979;0.338688;,
  -0.000001;-0.999159;0.040997;,
  0.000001;0.320857;0.947128;,
  -0.634909;0.290814;0.715764;,
  -0.940459;0.301552;0.156855;,
  0.940459;0.301552;0.156855;,
  0.634911;0.290794;0.715770;,
  -0.000001;-0.816213;0.577751;,
  -0.391003;-0.795026;0.463736;,
  -0.614176;-0.765701;0.191023;,
  -0.621594;-0.768135;-0.153590;,
  -0.409543;-0.750187;-0.519129;,
  -0.000002;-0.717980;-0.696064;,
  0.409541;-0.750186;-0.519130;,
  0.621594;-0.768135;-0.153591;,
  0.614176;-0.765701;0.191024;,
  0.391002;-0.795025;0.463738;,
  -0.660572;0.009108;0.750707;,
  -0.000002;0.012132;0.999926;,
  -0.966481;0.003115;0.256720;,
  -0.939014;-0.004172;-0.343852;,
  -0.533408;-0.010261;-0.845796;,
  -0.000001;-0.012131;-0.999926;,
  0.533407;-0.010261;-0.845796;,
  0.939014;-0.004172;-0.343852;,
  0.966481;0.003114;0.256719;,
  0.660571;0.009108;0.750709;;
  110;
  3;0,2,1;,
  3;0,3,2;,
  3;0,4,3;,
  3;0,5,4;,
  3;0,6,5;,
  3;0,7,6;,
  3;0,8,7;,
  3;0,9,8;,
  3;0,10,9;,
  3;0,1,10;,
  4;1,2,12,11;,
  4;2,3,13,12;,
  4;3,4,14,13;,
  4;4,5,15,14;,
  4;5,6,16,15;,
  4;6,7,17,16;,
  4;7,8,18,17;,
  4;8,9,19,18;,
  4;9,10,20,19;,
  4;10,1,11,20;,
  4;21,22,22,21;,
  4;22,23,23,22;,
  4;23,14,24,23;,
  4;14,15,25,24;,
  4;15,16,26,25;,
  4;16,17,27,26;,
  4;17,18,28,27;,
  4;18,29,29,28;,
  4;29,30,30,29;,
  4;30,21,21,30;,
  4;92,93,32,31;,
  4;93,94,33,32;,
  4;94,24,34,33;,
  4;24,25,35,34;,
  4;25,26,36,35;,
  4;26,27,37,36;,
  4;27,28,38,37;,
  4;28,95,39,38;,
  4;95,96,40,39;,
  4;96,92,31,40;,
  4;31,32,42,41;,
  4;32,33,43,42;,
  4;33,34,44,43;,
  4;34,35,45,44;,
  4;35,36,46,45;,
  4;36,37,47,46;,
  4;37,38,48,47;,
  4;38,39,49,48;,
  4;39,40,50,49;,
  4;40,31,41,50;,
  4;41,42,52,51;,
  4;42,43,53,52;,
  4;43,44,54,53;,
  4;44,45,55,54;,
  4;45,46,56,55;,
  4;46,47,57,56;,
  4;47,48,58,57;,
  4;48,49,59,58;,
  4;49,50,60,59;,
  4;50,41,51,60;,
  4;51,52,62,61;,
  4;52,53,63,62;,
  4;53,54,64,63;,
  4;54,55,65,64;,
  4;55,56,66,65;,
  4;56,57,67,66;,
  4;57,58,68,67;,
  4;58,59,69,68;,
  4;59,60,70,69;,
  4;60,51,61,70;,
  4;71,72,72,71;,
  4;72,73,73,72;,
  4;73,74,74,73;,
  4;74,75,75,74;,
  4;75,76,76,75;,
  4;76,77,77,76;,
  4;77,78,78,77;,
  4;78,79,79,78;,
  4;79,80,80,79;,
  4;80,71,71,80;,
  4;97,98,82,81;,
  4;98,99,83,82;,
  4;99,100,84,83;,
  4;100,101,85,84;,
  4;101,102,86,85;,
  4;102,103,87,86;,
  4;103,104,88,87;,
  4;104,105,89,88;,
  4;105,106,90,89;,
  4;106,97,81,90;,
  3;81,82,91;,
  3;82,83,91;,
  3;83,84,91;,
  3;84,85,91;,
  3;85,86,91;,
  3;86,87,91;,
  3;87,88,91;,
  3;88,89,91;,
  3;89,90,91;,
  3;90,81,91;,
  4;62,107,108,61;,
  4;62,63,109,107;,
  4;63,64,110,109;,
  4;65,111,110,64;,
  4;65,66,112,111;,
  4;66,67,113,112;,
  4;67,68,114,113;,
  4;69,115,114,68;,
  4;69,70,116,115;,
  4;70,61,108,116;;
 }
 MeshTextureCoords {
  130;
  0.050000;0.000000;,
  0.100000;0.100000;,
  0.000000;0.100000;,
  0.150000;0.000000;,
  0.200000;0.100000;,
  0.250000;0.000000;,
  0.300000;0.100000;,
  0.350000;0.000000;,
  0.400000;0.100000;,
  0.450000;0.000000;,
  0.500000;0.100000;,
  0.550000;0.000000;,
  0.600000;0.100000;,
  0.650000;0.000000;,
  0.700000;0.100000;,
  0.750000;0.000000;,
  0.800000;0.100000;,
  0.850000;0.000000;,
  0.900000;0.100000;,
  0.950000;0.000000;,
  1.000000;0.100000;,
  0.100000;0.200000;,
  0.000000;0.200000;,
  0.200000;0.200000;,
  0.300000;0.200000;,
  0.400000;0.200000;,
  0.500000;0.200000;,
  0.600000;0.200000;,
  0.700000;0.200000;,
  0.800000;0.200000;,
  0.900000;0.200000;,
  1.000000;0.200000;,
  0.100000;0.300000;,
  0.000000;0.300000;,
  0.200000;0.300000;,
  0.300000;0.300000;,
  0.400000;0.300000;,
  0.500000;0.300000;,
  0.600000;0.300000;,
  0.700000;0.300000;,
  0.800000;0.300000;,
  0.900000;0.300000;,
  1.000000;0.300000;,
  0.100000;0.400000;,
  0.000000;0.400000;,
  0.200000;0.400000;,
  0.300000;0.400000;,
  0.400000;0.400000;,
  0.500000;0.400000;,
  0.600000;0.400000;,
  0.700000;0.400000;,
  0.800000;0.400000;,
  0.900000;0.400000;,
  1.000000;0.400000;,
  0.100000;0.500000;,
  0.000000;0.500000;,
  0.200000;0.500000;,
  0.300000;0.500000;,
  0.400000;0.500000;,
  0.500000;0.500000;,
  0.600000;0.500000;,
  0.700000;0.500000;,
  0.800000;0.500000;,
  0.900000;0.500000;,
  1.000000;0.500000;,
  0.100000;0.600000;,
  0.000000;0.600000;,
  0.200000;0.600000;,
  0.300000;0.600000;,
  0.400000;0.600000;,
  0.500000;0.600000;,
  0.600000;0.600000;,
  0.700000;0.600000;,
  0.800000;0.600000;,
  0.900000;0.600000;,
  1.000000;0.600000;,
  0.100000;0.700000;,
  0.000000;0.700000;,
  0.200000;0.700000;,
  0.300000;0.700000;,
  0.400000;0.700000;,
  0.500000;0.700000;,
  0.600000;0.700000;,
  0.700000;0.700000;,
  0.800000;0.700000;,
  0.900000;0.700000;,
  1.000000;0.700000;,
  0.000000;0.700000;,
  0.100000;0.700000;,
  0.100000;0.800000;,
  0.000000;0.800000;,
  0.200000;0.700000;,
  0.200000;0.800000;,
  0.300000;0.700000;,
  0.300000;0.800000;,
  0.400000;0.700000;,
  0.400000;0.800000;,
  0.500000;0.700000;,
  0.500000;0.800000;,
  0.600000;0.700000;,
  0.600000;0.800000;,
  0.700000;0.700000;,
  0.700000;0.800000;,
  0.800000;0.700000;,
  0.800000;0.800000;,
  0.900000;0.700000;,
  0.900000;0.800000;,
  1.000000;0.700000;,
  1.000000;0.800000;,
  0.100000;0.900000;,
  0.000000;0.900000;,
  0.200000;0.900000;,
  0.300000;0.900000;,
  0.400000;0.900000;,
  0.500000;0.900000;,
  0.600000;0.900000;,
  0.700000;0.900000;,
  0.800000;0.900000;,
  0.900000;0.900000;,
  1.000000;0.900000;,
  0.050000;1.000000;,
  0.150000;1.000000;,
  0.250000;1.000000;,
  0.350000;1.000000;,
  0.450000;1.000000;,
  0.550000;1.000000;,
  0.650000;1.000000;,
  0.750000;1.000000;,
  0.850000;1.000000;,
  0.950000;1.000000;;
 }
}
