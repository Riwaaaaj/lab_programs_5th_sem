clc;
clear;
t = -5 : 0.01 : 5;
u = double(t == 0)
plot(t, u, 'LineWidth', 3);
xlabel('Time (t)');
ylabel('u(t)');
title('Impulse Signal: Riwaj Karki');
grid on;
axis([-5, 5, -2, 2]);