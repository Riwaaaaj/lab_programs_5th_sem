% Frequency Modulation
fm = 25; % input('message frequency = ');
fc = 200; % input('carrier frequency = ');
mi = 40; % input('modulation index = ');
t = 0:0.0001:0.1;

m = cos(2*pi*fm*t); % Message signal
subplot(4,1,1);
plot(t, m);
title('Message Signal');
xlabel('Time');
ylabel('Amplitude');
grid on;

c = cos(2*pi*fc*t); % Carrier signal
subplot(4,1,2);
plot(t, c);
title('Carrier Signal');
xlabel('Time');
ylabel('Amplitude');
grid on;

% FM signal: frequency varies based on message signal
y = cos(2*pi*fc*t + mi*sin(2*pi*fm*t)); 
subplot(4,1,3);
plot(t, y);
title('Frequency Modulated Signal');
xlabel('Time');
ylabel('Amplitude');
grid on;
