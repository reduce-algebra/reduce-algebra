% Rules
%trig1:={sin(~x)^2+cos(~x)^2=>1, cos(~x)^2+sin(~x)^2=>1};
trig1:={sin(~x)^2=>(1-cos(x)^2)};
let trig1;
trig2:={tan (~x)=>(sin (x)/cos (x))};
let trig2;
end;