clc;
clear;
t = -5 : 0.01 : 5;
u = 2 .^ -t .* double(t >= 0)
plot(t, u, 'LineWidth', 3);
xlabel('Time (t)');
ylabel('u(t)');
title('Exponential Decreasing Signal: Riwaj Karki');
grid on;
axis([-5, 10, 0, 2]);