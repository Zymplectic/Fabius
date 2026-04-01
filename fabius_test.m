clc, clear variables, close all
%demo file using fabius.m
x = linspace(-0.1, 1.3, 1000);

y_fab = fabius(x); %fabius function
y_fabd = fabius(x, 1); %derivatives
y_fabdd = fabius(x, 2);
y_fabi = fabius(x, -1); %anti-derivatives
y_fabii = fabius(x, -2);

figure
hold on
plot(x, y_fab); 
plot(x, y_fabd);
plot(x, y_fabdd);
plot(x, y_fabi);
plot(x, y_fabii);
xlabel('x');
ylabel('function value');
ylim([-1,2.5])
xlim([x(1),x(end)])
grid on
legend({'fab(x)', 'fabd(x)', 'fabdd(x)', 'fabi(x)', 'fabii(x)'});
