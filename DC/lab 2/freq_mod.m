% 2)Frequency modulation:
fm=25;%input(‘message frequency= ’);
fc=200; %input(‘carrier frequency= ’);
mi=40 %input(‘modulation index= ’);
t=0:0.0001:0.1;
m=cos(2*pi*fm*t);
subplot(4,1,1);
plot(t, m);
grid on;

c=cos(2*pi*fc*t);
subplot(4,1,2);
plot(t,c);
grid on;
Ma=Am/Ac;
y=cos(2*pi*fc*t+(mi.*sin(2*pi*fm*t)));

subplot(4,1,3);
plot(t, y);
grid on;
title(‘modulation signal’);

3)Phase modulation:
t=0:0.0001:0.1
fm=40; %input(‘enter the message frequency= ‘);
fc=200; %input(‘enter the carrier frequency= ‘);
mi=4*pi; %input(‘enter modulation Index= ‘);

mt=cos(2*pi*fm*t);
subplot(3,1,1);
plot (t, mt);
grid on;

ct=cos(2*pi*fc*t+mi*mt);
subplot(3,1,3);
plot(t, y);
grid on;