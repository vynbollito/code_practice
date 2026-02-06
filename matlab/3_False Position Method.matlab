function xr = falsePosition(f,xl,xu,es)
% x = sym('x') console
% Example: alsePosition(-25+82*x-90*x^2+44*x^3-8*x^4+0.7*x^5,0.5,1,0.0001)
% Substitute in 'x' the xl value in f(function) and save in fxl
fxl = subs(f,xl);
% Does the same but, now substitute xu in f and save in fxl
fxu = subs(f,xu);

% if product of evaluation of f(xl) && f(xu), there's no root
while fxl*fxu > 0
    disp('This function does not have root');
    xl = input('Enter a new xl: ');
    xu = input('Enter a new xu: ');
    fxl = subs(f,xl);
    fxu = subs(f,xu);
end
% f(xl) && f(xu) are valid
error = 100;                        % starting value
n = 1;                              % first step
% xr(n) = (xl+xu)/2; 
xr(n) = eval(xu - fxu*(xl-xu)/(fxl-fxu));  % (n) save in array, bisecction operation

while error > es                    % calculte xr
    fxr = subs(f,xr(n));            % get f(xr)
    if fxl*fxr < 0                  % find in which side is the root 
        xu = xr(n);                 % left
        fxu = fxr;                      
    else
        xl = xr(n);                 % right
        fxl = fxr;
    end

    xr(n+1) = xu - fxu*(xl-xu)/(fxl-fxu);
    error = abs((xr(n+1)-xr(n))/xr(n+1))*100;
    n = n+1;
end
fprintf("\nIterations: %d\n",n);
fprintf("\n\tResulting xr through calculations\n");