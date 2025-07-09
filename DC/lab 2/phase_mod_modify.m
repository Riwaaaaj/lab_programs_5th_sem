% Phase Modulation
t = 0:0.0001:0.1;
fm = input('Enter the message frequency: ');
fc = input('Enter the carrier frequency: ');
mi = pi * input('Enter modulation index: ');

mt = cos(2*pi*fm*t);
subplot(3,1,1);
plot(t, mt);
title('Message Signal');
xlabel('Time');
ylabel('Amplitude');
grid on;

ct = cos(2*pi*fc*t);
subplot(3,1,2);
plot(t, ct);
title('Carrier Signal');
xlabel('Time');
ylabel('Amplitude');
grid on;

y = cos(2*pi*fc*t + mi * mt);
subplot(3,1,3);
plot(t, y);
title('Phase Modulated Signal');
xlabel('Time');
ylabel('Amplitude');
grid on;
