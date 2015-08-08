#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Author: darkbull
# @Date:   2014-05-31 10:02:21
# @Last Modified by:   darkbull
# @Last Modified time: 2014-06-02 15:29:20

"""Web控制树莓派小车
"""

import tornado.web
import tornado.ioloop
import codecs
import RPi.GPIO as GPIO
import time
import atexit
import math
atexit.register(GPIO.cleanup)

GPIO.setmode(GPIO.BCM)

IN1 = 17
IN2 = 22
IN3 = 23
IN4 = 24

# 左边轮速度控制
PWM_L = 8
PWM_R = 7

GPIO.setup(IN1, GPIO.OUT, initial=False)
GPIO.setup(IN2, GPIO.OUT, initial=False)
GPIO.setup(IN3, GPIO.OUT, initial=False)
GPIO.setup(IN4, GPIO.OUT, initial=False)

GPIO.setup(PWM_L, GPIO.OUT, initial=False)
GPIO.setup(PWM_R, GPIO.OUT, initial=False)
pwm_l = GPIO.PWM(PWM_L, 50)
pwm_l.start(0)
pwm_r = GPIO.PWM(PWM_R, 50)
pwm_r.start(0)

def front():
    GPIO.output(IN1, True)
    GPIO.output(IN2, False)
    GPIO.output(IN3, True)
    GPIO.output(IN4, False)

def back():
    GPIO.output(IN1, False)
    GPIO.output(IN2, True)
    GPIO.output(IN3, False)
    GPIO.output(IN4, True)

# def left():
#     # GPIO.output(IN1, False)
#     # GPIO.output(IN2, True)
#     GPIO.output(IN1, False)
#     GPIO.output(IN2, False)
#     GPIO.output(IN3, True)
#     GPIO.output(IN4, False)

# def right():
#     # GPIO.output(IN1, True)
#     # GPIO.output(IN2, False)
#     GPIO.output(IN1, False)
#     GPIO.output(IN2, False)
#     GPIO.output(IN3, False)
#     GPIO.output(IN4, True)

def stop():
    GPIO.output(IN1, False)
    GPIO.output(IN2, False)
    GPIO.output(IN3, False)
    GPIO.output(IN4, False)


def run(x, y, r):
    """小车运行
    """
    if x * x + y * y > r * r:
        return

    speed_min = 15
    speed_max = 100
    speed_delta = speed_max - speed_min
    # y轴为小车的运行方向，速度以y轴的值为基准
    if y < 0:
        back()
    elif y > 0:
        front()
    else:
        stop()
        return

    t = abs(y) * 100.0 / r
    if t < 20:  # 电压太小，驱动不起来
        t = 20 
    d = math.atan2(x, y) * 180 / math.pi
    
    if x < 0: # 往左边偏, 右轮的速度比左轮快
        t2 = t * (abs(90 + d) / 90)
        pwm_r.ChangeDutyCycle(t)
        pwm_l.ChangeDutyCycle(t2)
    elif x > 0: # 往右边偏, 左边的速度比右轮快
        t2 = t * (abs(90 - d) / 90)
        pwm_l.ChangeDutyCycle(t)
        pwm_r.ChangeDutyCycle(t2)
    print x, y, t, t2

class CarController(tornado.web.RequestHandler):
    def get(self):
        with codecs.open('webcar.html', 'r', encoding='utf-8') as fp:
            self.write(fp.read())

    def post(self):
        r = int(self.get_argument('r'))
        x = int(self.get_argument('x'))
        y = int(self.get_argument('y'))
        run(x, y, r)
        self.write('ok')


if __name__ == '__main__':
    app = tornado.web.Application([('/', CarController)], static_path='static', debug=True)
    app.listen(18080)
    tornado.ioloop.IOLoop.instance().start()
