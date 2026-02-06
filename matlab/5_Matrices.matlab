% Matrix definition
% a = [a11, a12, a13; a21, a22,a23; a31, a32, a33];
% add a semicolon to end a row
a = [0.3,0.52,1; 0.5,1,1.9; 0.1,0.3,0.5];
b = [-0.01; 0.67; -0.44];
% Duplicate the matrix
aux1 = a;
aux2 = a;
aux3 = a;
% : temporally set the values, meaning they will not change with this operation
aux1(:,1) = b;      % column 1 changes
aux2(:,2) = b;      % column 2 changes
aux3(:,3) = b;      % column 3 changes

% Display as vector
x(1) = det(aux1)/det(a);
x(2) = det(aux2)/det(a);
x(3) = det(aux3)/det(a);