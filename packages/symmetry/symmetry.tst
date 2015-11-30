% test symmetry package
% implementation of theory of linear representations
% for small groups 

availablegroups();

printgroup(d4);

generators(d4);

charactertable(d4);

characternr(d4,1);
characternr(d4,2);
characternr(d4,3);
characternr(d4,4);
characternr(d4,5);
irreduciblereptable(d4);
irreduciblerepnr(d4,1);
irreduciblerepnr(d4,2);
irreduciblerepnr(d4,3);
irreduciblerepnr(d4,4);
irreduciblerepnr(d4,5);


rr:=mat((1,0,0,0,0),
        (0,0,1,0,0),
        (0,0,0,1,0),
        (0,0,0,0,1),
        (0,1,0,0,0));

sp:=mat((1,0,0,0,0),
        (0,0,1,0,0),
        (0,1,0,0,0),
        (0,0,0,0,1),
        (0,0,0,1,0));

rep:={d4,rd4=rr,sd4=sp};

canonicaldecomposition(rep);

character(rep);

symmetrybasis(rep,1);
symmetrybasis(rep,2);
symmetrybasis(rep,3);
symmetrybasis(rep,4);
symmetrybasis(rep,5);
symmetrybasispart(rep,5);
allsymmetrybases(rep);


% Ritz matrix from Stiefel, Faessler p. 200
m:=mat((eps,a,a,a,a),
       (a  ,d,b,g,b),
       (a  ,b,d,b,g),
       (a  ,g,b,d,b),
       (a  ,b,g,b,d));


diagonalize(m,rep);

% eigenvalues are obvious. Eigenvectors may be obtained with
% the coordinate transformation matrix given by allsymmetrybases.

r1:=mat((0,1,0),
        (0,0,1),
        (1,0,0));

repc3:={c3,rc3=r1};

mc3:=mat((a,b,c),
         (c,a,b),
         (b,c,a));

diagonalize(mc3,repc3); 

% note difference between real and complex case

on complex;
diagonalize(mc3,repc3); 
off complex;

end;
