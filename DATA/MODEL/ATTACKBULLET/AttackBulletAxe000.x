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
 28;
 -1.19073;92.82137;0.46572;,
 1.19073;92.82137;0.46572;,
 0.82735;-18.45795;-26.55388;,
 -0.82735;-18.45795;-26.55388;,
 1.19073;-92.14537;0.46572;,
 -1.19073;-92.14537;0.46572;,
 1.19073;92.82137;0.46572;,
 2.22111;92.82137;25.41497;,
 2.22111;-18.45795;-1.60464;,
 0.82735;-18.45795;-26.55388;,
 2.22111;-92.14537;25.41497;,
 1.19073;-92.14537;0.46572;,
 2.22111;92.82137;25.41497;,
 -2.22111;92.82137;25.41497;,
 -2.22111;-18.45795;-1.60464;,
 2.22111;-18.45795;-1.60464;,
 -2.22111;-92.14537;25.41497;,
 2.22111;-92.14537;25.41497;,
 -2.22111;92.82137;25.41497;,
 -1.19073;92.82137;0.46572;,
 -0.82735;-18.45795;-26.55388;,
 -2.22111;-18.45795;-1.60464;,
 -1.19073;-92.14537;0.46572;,
 -2.22111;-92.14537;25.41497;,
 1.19073;92.82137;0.46572;,
 -1.19073;92.82137;0.46572;,
 -1.19073;-92.14537;0.46572;,
 1.19073;-92.14537;0.46572;;
 
 10;
 4;0,1,2,3;,
 4;3,2,4,5;,
 4;6,7,8,9;,
 4;9,8,10,11;,
 4;12,13,14,15;,
 4;15,14,16,17;,
 4;18,19,20,21;,
 4;21,20,22,23;,
 4;18,7,24,25;,
 4;26,27,10,23;;
 
 MeshMaterialList {
  3;
  10;
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2;;
  Material {
   1.000000;0.984314;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   1.000000;0.984314;0.000000;;
  }
  Material {
   0.000000;0.090196;0.584314;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.090196;0.584314;;
  }
  Material {
   1.000000;0.388235;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   1.000000;0.388235;0.000000;;
  }
 }
 MeshNormals {
  14;
  0.000000;0.235953;-0.971764;,
  0.000000;-0.056598;-0.998397;,
  0.000000;-0.344265;-0.938873;,
  0.998771;0.010151;-0.048519;,
  0.998819;-0.002589;-0.048521;,
  0.998705;-0.015328;-0.048516;,
  0.000000;-0.235953;0.971764;,
  0.000000;0.056598;0.998397;,
  0.000000;0.344265;0.938873;,
  -0.998771;0.010151;-0.048519;,
  -0.998819;-0.002589;-0.048521;,
  -0.998705;-0.015328;-0.048516;,
  0.000000;1.000000;0.000000;,
  0.000000;-1.000000;-0.000000;;
  10;
  4;0,0,1,1;,
  4;1,1,2,2;,
  4;3,3,4,4;,
  4;4,4,5,5;,
  4;6,6,7,7;,
  4;7,7,8,8;,
  4;9,9,10,10;,
  4;10,10,11,11;,
  4;12,12,12,12;,
  4;13,13,13,13;;
 }
 MeshTextureCoords {
  28;
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.500000;,
  0.000000;0.500000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.500000;,
  0.000000;0.500000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.500000;,
  0.000000;0.500000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.500000;,
  0.000000;0.500000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;;
 }
}
