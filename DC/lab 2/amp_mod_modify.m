% 1) Amplitude Modulation
clc;
clear all;
close all;

t = 0:0.0001:0.1;

Am = 1; % input('message amplitude, Am = ');
Ac = 1; % input('carrier amplitude, Ac = ');
Fm = 20; % input('message frequency, Fm = ');
Fc = 200; % input('carrier frequency, Fc = ');

Mt = Am * cos(2 * pi * Fm * t); % Message signal
subplot(4,1,1);
plot(t, Mt, 'linewidth', 1);
xlabel('Time');
ylabel('Amplitude');
title('Message Signal');
grid on;

Ct = Ac * cos(2 * pi * Fc * t); % Carrier signal
subplot(4,1,2);
plot(t, Ct, 'r', 'linewidth', 1);
xlabel('Time');
ylabel('Amplitude');
title('Carrier Signal');
grid on;

% Modulated signal
y = (Ac + Mt) .* cos(2 * pi * Fc * t);
subplot(4,1,3);
plot(t, y, 'b', 'linewidth', 1);
xlabel('Time');
ylabel('Amplitude');
title('Amplitude Modulated Signal');
grid on;

% Optional 4th Plot

% demod = abs(y); % Simple envelope detection (rectifier)
% subplot(4,1,4);
% plot(t, demod, 'g', 'linewidth', 1);
% xlabel('Time');
% ylabel('Amplitude');
% title('Demodulated Signal (Envelope)');
% grid on;
