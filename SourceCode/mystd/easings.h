//*************************************************************************************************************
//
// イージング処理[easings.h]
// Author : Sekine Ikuto
//
//*************************************************************************************************************
#pragma once
#ifndef _EASINGS_H_
#define _EASINGS_H_

//-------------------------------------------------------------------------------------------------------------
// インクルードファイル
//-------------------------------------------------------------------------------------------------------------
#include "utility.h"

//-------------------------------------------------------------------------------------------------------------
// マクロ定義
//-------------------------------------------------------------------------------------------------------------
#define _BETGIN_EASING namespace easing {
#define _END_EASING }
#define _EASING _MYSTD easing::

/*[memo]
$ argument -> x_axis : x
$ return   -> y_axis : y
$
$  |
$ y|
$  |______
$     x
*/

_BEGIN_MYSTD
_BETGIN_EASING

float InSine(float x)
{
	return 1.0f - std::cosf((x * fPi) / 2.0f);
}

float OutSine(float x)
{
	return std::sinf((x * fPi) / 2.0f);
}

float InOutSine(float x)
{
	return -(std::cosf(fPi * x) - 1) / 2;
}

float InQuad(float x)
{
	return x * x;
}

float OutQuad(float x)
{
	return 1.0f - (1.0f - x) * (1.0f - x);
}

float InOutQuad(float x)
{
	return x < 0.5f ?
		2.0f * x * x :
		1.0f - std::powf(-2.0f * x + 2.0f, 2.0f) / 2.0f;
}

float InCubic(float x)
{
	return x * x * x;
}

float OutCubic(float x)
{
	return 1.0f - std::powf(1.0f - x, 3.0f);
}

float InOutCubic(float x)
{
	return x < 0.5f ?
		4.0f * x * x * x :
		1.0f - std::powf(-2.0f * x + 2.0f, 3.0f) / 2.0f;
}

float InQuart(float x)
{
	return x * x * x * x;
}

float OutQuart(float x)
{
	return 1.0f - std::powf(1.0f - x, 4.0f);
}

float InOutQuart(float x)
{
	return x < 0.5f ?
		8.0f * x * x * x * x :
		1.0f - std::powf(-2.0f * x + 2.0f, 4.0f) / 2.0f;
}

float InQuint(float x)
{
	return x * x * x * x * x;
}

float OutQuint(float x)
{
	return 1.0f - std::powf(1.0f - x, 5.0f);
}

float InOutQuint(float x)
{
	return x < 0.5f ?
		16.0f * x * x * x * x * x :
		1.0f - std::powf(-2.0f * x + 2.0f, 5.0f) / 2.0f;
}

float InExpo(float x)
{
	return x == 0.0f ?
		0.0f :
		std::powf(2.0f, 10.0f * x - 10.0f);
}

float OutExpo(float x)
{
	return x == 1.0f ?
		1.0f :
		1.0f - std::powf(2.0f, -10.0f * x);
}

float InOutExpo(float x)
{
	return x == 0.0f ?
		0.0f :
		x == 1.0f ?
		1.0f :
		x < 0.5f ?
		std::powf(2.0f, 20.0f * x - 10.0f) / 2.0f :
		(2.0f - std::powf(2.0f, -20.0f * x + 10.0f)) / 2.0f;
}

float InCirc(float x)
{
	return 1.0f - std::sqrtf(1.0f - std::powf(x, 2.0f));
}

float OutCirc(float x)
{
	return std::sqrtf(1.0f - std::powf(x - 1.0f, 2.0f));
}

float InOutCirc(float x)
{
	return x < 0.5f ?
		(1.0f - std::sqrtf(1.0f - std::powf(2.0f * x, 2.0f))) / 2.0f :
		(std::sqrtf(1.0f - std::powf(-2.0f * x + 2.0f, 2.0f)) + 1.0f) / 2.0f;
}

float InBack(float x)
{
	const float c1 = 1.70158f;
	const float c3 = c1 + 1.0f;
	return c3 * x * x * x - c1 * x * x;
}

float OutBack(float x)
{
	const float c1 = 1.70158f;
	const float c3 = c1 + 1.0f;
	return 1.0f + c3 * std::powf(x - 1.0f, 3.0f) + c1 * std::powf(x - 1.0f, 2.0f);
}

float InOutBack(float x)
{
	const float c1 = 1.70158f;
	const float c2 = c1 * 1.525f;
	return x < 0.5f ?
		(std::powf(2.0f * x, 2.0f) * ((c2 + 1.0f) * 2.0f * x - c2)) / 2.0f :
		(std::powf(2.0f * x - 2.0f, 2.0f) * ((c2 + 1.0f) * (x * 2.0f - 2.0f) + c2) + 2.0f) / 2.0f;
}

float InElastic(float x)
{
	const float c4 = (2.0f * fPi) / 3.0f;

	return x == 0.0f ?
		0.0f :
		x == 1.0f ?
		1 :
		-std::powf(2.0f, 10.0f * x - 10.0f) * std::sinf((x * 10.0f - 10.75f) * c4);
}

float OutElastic(float x)
{
	const float c4 = (2.0f * fPi) / 3.0f;

	return x == 0.0f ?
		0.0f :
		x == 1.0f ?
		1.0f :
		std::powf(2.0f, -10.0f * x) * std::sinf((x * 10.0f - 0.75f) * c4) + 1.0f;
}

float InOutElastic(float x)
{
	const float c5 = (2.0f * fPi) / 4.5f;

	return x == 0.0f ?
		0.0f :
		x == 1.0f ?
		1.0f :
		x < 0.5f ?
		-(std::powf(2.0f, 20.0f * x - 10.0f) * std::sinf((20.0f * x - 11.125f) * c5)) / 2.0f :
		(std::powf(2.0f, -20.0f * x + 10.0f) * std::sinf((20.0f * x - 11.125f) * c5)) / 2.0f + 1.0f;
}

float OutBounce(float x)
{
	const float n1 = 7.5625f;
	const float d1 = 2.75f;

	if (x < 1.0f / d1) {
		return n1 * x * x;
	}
	else if (x < 2.0f / d1) {
		return n1 * (x -= 1.5f / d1) * x + 0.75f;
	}
	else if (x < 2.5f / d1) {
		return n1 * (x -= 2.25f / d1) * x + 0.9375f;
	}
	else {
		return n1 * (x -= 2.625f / d1) * x + 0.984375f;
	}
}

float InBounce(float x)
{
	return 1.0f - OutBounce(1.0f - x);
}

float InOutBounce(float x)
{
	return x < 0.5f ?
		(1.0f - OutBounce(1.0f - 2.0f * x)) / 2.0f :
		(1.0f + OutBounce(2.0f * x - 1.0f)) / 2.0f;
}

_END_EASING
_END_MYSTD

#endif