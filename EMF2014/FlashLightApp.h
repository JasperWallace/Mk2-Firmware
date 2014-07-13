/*
 TiLDA Mk2

 FlashLightApp
 Torch Mode - Press the light button and both RGB LEDs light up.

 The MIT License (MIT)

 Copyright (c) 2014 Electromagnetic Field LTD

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
 */

#ifndef _FLASH_LIGHT_APP_H_
#define _FLASH_LIGHT_APP_H_

#include <Arduino.h>
#include <FreeRTOS_ARM.h>
#include "EMF2014Config.h"
#include "App.h"
#include "RGBTask.h"
#include "ButtonSubscription.h"

class FlashLightApp: public App {
public:
	FlashLightApp(RGBTask rgbTask): _rgbTask(rgbTask), _lightLevel(255) {};
	String getName();
protected:
    void task();
    void afterSuspension();
    void beforeResume();
private:
	void updateLeds();
	RGBTask _rgbTask;
	uint8_t _lightLevel;
	ButtonSubscription *_pbuttons;
};

#endif // _FLASH_LIGHT_APP_H_