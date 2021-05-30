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
 56;
 -16.64271;0.55701;-114.72713;,
 -16.64271;313.23919;-182.41970;,
 20.88502;22.78842;-53.64712;,
 -16.64271;313.23919;-182.41970;,
 -54.17047;22.78842;-53.64712;,
 -16.64271;313.23919;-182.41970;,
 -16.64271;0.55701;-114.72713;,
 -16.64271;16.87561;-13.43429;,
 -16.64271;307.33274;120.68082;,
 20.88502;-2.12866;48.72558;,
 -16.64271;307.33274;120.68082;,
 -54.17047;-2.12866;48.72558;,
 -16.64271;307.33274;120.68082;,
 -16.64271;16.87561;-13.43429;,
 -77.07904;10.76957;-61.54523;,
 -211.03970;298.04873;-18.21199;,
 -43.06738;26.62953;3.45470;,
 -211.03970;298.04873;-18.21199;,
 -111.09076;-5.09021;3.45470;,
 -211.03970;298.04873;-18.21199;,
 -77.07904;10.76957;-61.54523;,
 35.59152;-0.51698;-61.54523;,
 130.90838;301.78963;-18.21199;,
 71.38235;-11.80192;3.45470;,
 130.90838;301.78963;-18.21199;,
 -0.19943;10.76783;3.45470;,
 130.90838;301.78963;-18.21199;,
 35.59152;-0.51698;-61.54523;,
 -153.04799;5.58561;106.78723;,
 -248.31490;179.16859;202.05440;,
 -119.90189;17.92714;-31.98817;,
 -248.31490;179.16859;202.05440;,
 -14.27259;17.92714;73.64108;,
 -248.31490;179.16859;202.05440;,
 -153.04799;5.58561;106.78723;,
 -10.49374;14.64474;-35.76702;,
 178.25276;175.89013;-224.51363;,
 24.17207;4.09474;-176.06220;,
 178.25276;175.89013;-224.51363;,
 129.80126;4.09474;-70.43286;,
 178.25276;175.89013;-224.51363;,
 -10.49374;14.64474;-35.76702;,
 6.85226;11.25497;116.99678;,
 256.36621;170.73595;244.54078;,
 50.46354;20.05944;-22.34702;,
 256.36621;170.73595;244.54078;,
 146.19623;2.45057;73.38567;,
 256.36621;170.73595;244.54078;,
 6.85226;11.25497;116.99678;,
 -151.71449;4.98954;-41.56976;,
 -224.87337;172.81265;-236.69883;,
 -110.60701;-1.27523;-183.41756;,
 -224.87337;172.81265;-236.69883;,
 -9.86652;11.25405;-82.67710;,
 -224.87337;172.81265;-236.69883;,
 -151.71449;4.98954;-41.56976;;
 
 24;
 3;0,1,2;,
 3;2,3,4;,
 3;4,5,6;,
 3;7,8,9;,
 3;9,10,11;,
 3;11,12,13;,
 3;14,15,16;,
 3;16,17,18;,
 3;18,19,20;,
 3;21,22,23;,
 3;23,24,25;,
 3;25,26,27;,
 3;28,29,30;,
 3;30,31,32;,
 3;32,33,34;,
 3;35,36,37;,
 3;37,38,39;,
 3;39,40,41;,
 3;42,43,44;,
 3;44,45,46;,
 3;46,47,48;,
 3;49,50,51;,
 3;51,52,53;,
 3;53,54,55;;
 
 MeshMaterialList {
  10;
  24;
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8,
  8;;
  Material {
   0.000000;0.131765;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.164706;1.000000;;
  }
  Material {
   0.000000;0.103529;0.633726;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.129412;0.792157;;
  }
  Material {
   0.000000;0.062745;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.076863;0.980000;;
  }
  Material {
   0.000000;0.043922;0.542745;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.032941;0.407059;;
  }
  Material {
   0.000000;0.028235;0.320000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.021176;0.240000;;
  }
  Material {
   0.000000;0.009412;0.128627;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.007059;0.096471;;
  }
  Material {
   1.000000;0.835294;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   1.000000;0.835294;0.000000;;
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.376471;0.000000;1.000000;;
   5.000000;
   1.000000;1.000000;1.000000;;
   1.000000;0.470588;0.000000;;
  }
  Material {
   1.000000;1.000000;1.000000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  24;
  0.864010;-0.106530;-0.492076;,
  0.000000;0.405306;0.914181;,
  -0.864009;-0.106530;-0.492076;,
  0.864010;0.211060;-0.457100;,
  0.000000;-0.226476;0.974017;,
  -0.864010;0.211061;-0.457100;,
  0.754238;0.426952;-0.498836;,
  -0.028820;0.061806;0.997672;,
  -0.811879;-0.303341;-0.498836;,
  0.844527;-0.194774;-0.498836;,
  0.020507;0.065039;0.997672;,
  -0.803513;0.324851;-0.498837;,
  -0.900256;-0.358572;-0.246912;,
  0.376539;0.846425;-0.376540;,
  -0.755714;0.612142;-0.232763;,
  0.543139;-0.640314;-0.543138;,
  -0.498386;0.860983;-0.101582;,
  0.709944;0.216732;-0.670079;,
  -0.788935;-0.579970;-0.203019;,
  0.674263;0.227541;-0.702563;,
  0.246912;-0.358573;0.900255;,
  0.232763;0.612142;0.755714;,
  0.153088;-0.752134;0.640983;,
  0.143598;0.776282;0.613812;;
  24;
  3;0,0,0;,
  3;1,1,1;,
  3;2,2,2;,
  3;3,3,3;,
  3;4,4,4;,
  3;5,5,5;,
  3;6,6,6;,
  3;7,7,7;,
  3;8,8,8;,
  3;9,9,9;,
  3;10,10,10;,
  3;11,11,11;,
  3;12,12,12;,
  3;13,13,13;,
  3;20,20,20;,
  3;14,14,14;,
  3;15,15,15;,
  3;21,21,21;,
  3;16,16,16;,
  3;17,17,17;,
  3;22,22,22;,
  3;18,18,18;,
  3;19,19,19;,
  3;23,23,23;;
 }
 MeshTextureCoords {
  56;
  0.000000;1.000000;,
  0.166670;0.000000;,
  0.333330;1.000000;,
  0.333330;0.000000;,
  0.666670;1.000000;,
  0.500000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.166670;0.000000;,
  0.333330;1.000000;,
  0.333330;0.000000;,
  0.666670;1.000000;,
  0.500000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.166670;0.000000;,
  0.333330;1.000000;,
  0.333330;0.000000;,
  0.666670;1.000000;,
  0.500000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.166670;0.000000;,
  0.333330;1.000000;,
  0.333330;0.000000;,
  0.666670;1.000000;,
  0.500000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.166670;0.000000;,
  0.333330;1.000000;,
  0.333330;0.000000;,
  0.666670;1.000000;,
  0.500000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.166670;0.000000;,
  0.333330;1.000000;,
  0.333330;0.000000;,
  0.666670;1.000000;,
  0.500000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.166670;0.000000;,
  0.333330;1.000000;,
  0.333330;0.000000;,
  0.666670;1.000000;,
  0.500000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.166670;0.000000;,
  0.333330;1.000000;,
  0.333330;0.000000;,
  0.666670;1.000000;,
  0.500000;0.000000;,
  1.000000;1.000000;;
 }
}