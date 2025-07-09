% 1)Amplitude modulation:
clc;
clear all;
close all;
t=0:0.0001:0.1

Am=1%input(‘message amplitude, Am= ’);
Ac=1%input(‘carrier amplitude, Ac= ’);
Fm=20%input(‘message frequency, Fm= ’);
Fc=200%input(‘carrier frequency, Fc= ’);

Mt=Am*cos(2*pi*Fm*t);
subplot(4,1,1);
plot(t, Mt, ‘linewidth’ ,1);
grid on
xlabel(‘time’)
ylabel(‘amplitude’)
title(‘message signal’)
grid on;

Ct=Ac*cos(2*pi*Fc*t);
subplot(4,1,2)
plot(t, Ct ,’r’ , ‘linewidth’ , 1);
xlabel(‘time’);
ylabel(‘amplitude’)
title(‘carrier signal’)
grid on;