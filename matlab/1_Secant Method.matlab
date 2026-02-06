% N starts at 2, because the row 1, is used to do some calculations, this does not change the performance
% Example:
% secante(8*exp(x)*sin(x)-1,0.3,0.5,0.2,0.11199053)
% N starts at 2, because the row 1, is used to do some calculations, this
% does not change the performance
% Example
% secante(8*exp(x)*sin(x)-1,0.3,0.5,0.2,0.11199053)

% The number of iterations depends on estimated error inserted
function xr = secante(f,xi,xi_1,es,xt)
xr(1)    = xi_1;    % Auxiliar element
xr(2)    = xi;      % First value of x
fx1      = zeros(1, 1000000);  % Saves evaluation of xi_1, preallocating to avoid affecting performance and memory use 
fx       = zeros(1, 1000000); % Saves evaluation of xi
n       = 2;        % Start of array
ea      = 99;       % Aproximated Error

fprintf("\n\tMetodo Secante\nN\tx-i-1\t\txi\t\tf(xi)\t\tf(xi-1)\t\tea\t\tet\t");
while ea >= es
	
    fx1(n)  = subs(f,xr(n-1));	
    fx(n)   = subs(f,xr(n));       
	ea      = abs(xr(n)-xr(n-1))/xr(n)*100; 
	et      = abs(xt-xr(n))/xt*100;
    
	fprintf("\n%d\t%d\t%d\t%d\t%d\t%d\t%d\t",n,xr(n-1),xr(n),fx(n),fx1(n),ea,et);
	xr(n+1) = xr(n)-fx(n)*((xr(n-1)-xr(n))/(fx1(n)-fx(n)));
	n = n+1;
end
fprintf("\n\n\txt: %d",xt);