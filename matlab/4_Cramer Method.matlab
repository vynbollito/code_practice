% Cramer Method
% Ax = B form
% [a], is a matrix [b] is a vertical array
 
function x = cramer(a,b)
n = size(a);
for i=1:n(1)
    aux = a;
    aux(:,i) = b;
    x(i) = det(aux)/det(a);
end