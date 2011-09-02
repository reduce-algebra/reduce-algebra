module definte;

algebraic <<

laplace2_rules :=

{ laplace2(1/~x,~f1,~x) => int(1/x*f1*e^(-s*x),x,0,infinity),
  laplace2(1/~x^(~a),~f1,~x) => int(1/x^a*f1*e^(-s*x),x,0,infinity),
  laplace2(1/sqrt(~x),~f1,~x)=> int(1/sqrt(x)*f1*e^(-s*x),x,0,infinity),
  laplace2(1/(sqrt(~x)*~x),~f1,~x) => 
		 int(1/(sqrt(x)*x)*f1*e^(-s*x),x,0,infinity),
  laplace2(1/(sqrt(~x)*~x^~a),~f1,~x) => 
		 int(1/(sqrt(x)*x^a)*f1*e^(-s*x),x,0,infinity),
  laplace2(~x^~a,~f1,~x) => int(x^a*f1*e^(-s*x),x,0,infinity),
  laplace2(~x,~f1,~x) => int(x*f1*e^(-s*x),x,0,infinity),
  laplace2(sqrt(~x),~f1,~x) => int(sqrt(x)*f1*e^(-s*x),x,0,infinity),
  laplace2(sqrt(~x)*~x,~f1,~x)=>int(sqrt(x)*x*f1*e^(-s*x),x,0,infinity),
  laplace2(sqrt(~x)*~x^~a,~f1,~x) => 
		    int(sqrt(x)*x^a*f1*e^(-s*x),x,0,infinity),
  laplace2(~b,~f1,~x) => int(b*f1*e^(-s*x),x,0,infinity),
  laplace2(~f1,~x) => int(f1*e^(-s*x),x,0,infinity)

};

let laplace2_rules;

hankel2_rules :=

{ hankel2(1/~x,~f1,~x) =>
		int(1/x*f1*besselj(n,2*(s*x)^(1/2)),x,0,infinity),
  hankel2(1/~x^(~a),~f1,~x) =>
		int(1/x^a*f1*besselj(n,2*(s*x)^(1/2)),x,0,infinity),
  hankel2(1/sqrt(~x),~f1,~x) => 
		int(1/sqrt(x)*f1*besselj(n,2*(s*x)^(1/2)),x,0,infinity),
  hankel2(1/(sqrt(~x)*~x),~f1,~x) => 
	    int(1/(sqrt(x)*x)*f1*besselj(n,2*(s*x)^(1/2)),x,0,infinity),
  hankel2(1/(sqrt(~x)*~x^~a),~f1,~x) => 
	  int(1/(sqrt(x)*x^a)*f1*besselj(n,2*(s*x)^(1/2)),x,0,infinity),
  hankel2(~x^~a,~f1,~x) =>
	  int(x^a*f1*besselj(n,2*(s*x)^(1/2)),x,0,infinity),
  hankel2(~x,~f1,~x) => int(x*f1*besselj(n,2*(s*x)^(1/2)),x,0,infinity),
  hankel2(sqrt(~x),~f1,~x) => 
	  int(sqrt(x)*f1*besselj(n,2*(s*x)^(1/2)),x,0,infinity),
  hankel2(sqrt(~x)*~x,~f1,~x) => 
	  int(sqrt(x)*x,f1,besselj(n,2*(s*x)^(1/2)),x,0,infinity),
  hankel2(sqrt(~x)*~x^~a,~f1,~x) => 
	  int(sqrt(x)*x^a*f1*besselj(n,2*(s*x)^(1/2)),x,0,infinity),
  hankel2(~b,~f1,~x) => int(b*f1*besselj(n,2*(s*x)^(1/2)),x,0,infinity),
  hankel2(~f1,~x) => int(f1*besselj(n,2*(s*x)^(1/2)),x,0,infinity)
};

let hankel2_rules;

Y_transform2_rules :=

{ Y_transform2(1/~x,~f1,~x) => 
		      int(1/x*f1*bessely(n,2*(s*x)^(1/2)),x,0,infinity),
  Y_transform2(1/~x^(~a),~f1,~x) => 
		    int(1/x^a*f1*bessely(n,2*(s*x)^(1/2)),x,0,infinity),
  Y_transform2(1/sqrt(~x),~f1,~x) => 
		int(1/sqrt(x)*f1*bessely(n,2*(s*x)^(1/2)),x,0,infinity),
  Y_transform2(1/(sqrt(~x)*~x),~f1,~x) => 
	    int(1/(sqrt(x)*x)*f1*bessely(n,2*(s*x)^(1/2)),x,0,infinity),
  Y_transform2(1/(sqrt(~x)*~x^~a),~f1,~x) => 
	  int(1/(sqrt(x)*x^a)*f1*bessely(n,2*(s*x)^(1/2)),x,0,infinity),
  Y_transform2(~x^~a,~f1,~x) => 
		int(x^a*f1*bessely(n,2*(s*x)^(1/2)),x,0,infinity),
  Y_transform2(~x,~f1,~x) =>
		int(x*f1*bessely(n,2*(s*x)^(1/2)),x,0,infinity),
  Y_transform2(sqrt(~x),~f1,~x) => 
		int(sqrt(x)*f1*bessely(n,2*(s*x)^(1/2)),x,0,infinity),
  Y_transform2(sqrt(~x)*~x,~f1,~x) => 
		int(sqrt(x)*x*f1*bessely(n,2*(s*x)^(1/2)),x,0,infinity),
  Y_transform2(sqrt(~x)*~x^~a,~f1,~x) => 
	      int(sqrt(x)*x^a*f1*bessely(n,2*(s*x)^(1/2)),x,0,infinity),
  Y_transform2(~b,~f1,~x) =>
	      int(b*f1*bessely(n,2*(s*x)^(1/2)),x,0,infinity),
  Y_transform2(~f1,~x) => int(f1*bessely(n,2*(s*x)^(1/2)),x,0,infinity)
};

let Y_transform2_rules;

K_transform2_rules :=

{ K_transform2(1/~x,~f1,~x) => 
		      int(1/x*f1*besselK(n,2*(s*x)^(1/2)),x,0,infinity),
  K_transform2(1/~x^(~a),~f1,~x) => 
		    int(1/x^a*f1*besselK(n,2*(s*x)^(1/2)),x,0,infinity),
  K_transform2(1/sqrt(~x),~f1,~x) => 
		int(1/sqrt(x)*f1*besselK(n,2*(s*x)^(1/2)),x,0,infinity),
  K_transform2(1/(sqrt(~x)*~x),~f1,~x) => 
	    int(1/(sqrt(x)*x)*f1*besselK(n,2*(s*x)^(1/2)),x,0,infinity),
  K_transform2(1/(sqrt(~x)*~x^~a),~f1,~x) => 
	  int(1/(sqrt(x)*x^a)*f1*besselK(n,2*(s*x)^(1/2)),x,0,infinity),
  K_transform2(~x^~a,~f1,~x) => 
	  int(x^a*f1*besselK(n,2*(s*x)^(1/2)),x,0,infinity),
  K_transform2(~x,~f1,~x) =>
	  int(x*f1*besselK(n,2*(s*x)^(1/2)),x,0,infinity),
  K_transform2(sqrt(~x),~f1,~x) => 
	  int(sqrt(x)*f1*besselK(n,2*(s*x)^(1/2)),x,0,infinity),
  K_transform2(sqrt(~x)*~x,~f1,~x) => 
	  int(sqrt(x)*x*f1*besselK(n,2*(s*x)^(1/2)),x,0,infinity),
  K_transform2(sqrt(~x)*~x^~a,~f1,~x) => 
	  int(sqrt(x)*x^a*f1*besselK(n,2*(s*x)^(1/2)),x,0,infinity),
  K_transform2(~b,~f1,~x) =>
	  int(b*f1*besselK(n,2*(s*x)^(1/2)),x,0,infinity),
  K_transform2(~f1,~x) => int(f1*besselK(n,2*(s*x)^(1/2)),x,0,infinity)
};

let K_transform2_rules;

struveh2_rules :=

{ struveh2(1/~x,~f1,~x) => 
		 int(1/x*f1*struveh(n,2*(s*x)^(1/2)),x,0,infinity),
  struveh2(1/~x^(~a),~f1,~x) => 
		 int(1/x^a*f1*struveh(n,2*(s*x)^(1/2)),x,0,infinity),
  struveh2(1/sqrt(~x),~f1,~x) => 
		int(1/sqrt(x)*f1*struveh(n,2*(s*x)^(1/2)),x,0,infinity),
  struveh2(1/(sqrt(~x)*~x),~f1,~x) => 
	    int(1/(sqrt(x)*x)*f1*struveh(n,2*(s*x)^(1/2)),x,0,infinity),
  struveh2(1/(sqrt(~x)*~x^~a),~f1,~x) => 
	  int(1/(sqrt(x)*x^a)*f1*struveh(n,2*(s*x)^(1/2)),x,0,infinity),
  struveh2(~x^~a,~f1,~x) => 
	  int(x^a*f1*struveh(n,2*(s*x)^(1/2)),x,0,infinity),
  struveh2(~x,~f1,~x) => 
	  int(x*f1*struveh(n,2*(s*x)^(1/2)),x,0,infinity),
  struveh2(sqrt(~x),~f1,~x) => 
	  int(sqrt(x)*f1*struveh(n,2*(s*x)^(1/2)),x,0,infinity),
  struveh2(sqrt(~x)*~x,~f1,~x) => 
	  int(sqrt(x)*x*f1*struveh(n,2*(s*x)^(1/2)),x,0,infinity),
  struveh2(sqrt(~x)*~x^~a,~f1,~x) => 
	  int(sqrt(x)*x^a*f1*struveh(n,2*(s*x)^(1/2)),x,0,infinity),
  struveh2(~b,~f1,~x) => 
	  int(b*f1*struveh(n,2*(s*x)^(1/2)),x,0,infinity),
  struveh2(~f1,~x) => int(f1*struveh(n,2*(s*x)^(1/2)),x,0,infinity)
};

let struveh2_rules;

fourier_sin2_rules :=

{ fourier_sin2(1/~x,~f1,~x) => int(1/x*f1*sin(s*x),x,0,infinity),
  fourier_sin2(1/~x^(~a),~f1,~x) => int(1/x^a*f1*sin(s*x),x,0,infinity),
  fourier_sin2(1/sqrt(~x),~f1,~x) =>
				int(1/sqrt(x)*f1*sin(s*x),x,0,infinity),
  fourier_sin2(1/(sqrt(~x)*~x),~f1,~x) => 
		 int(1/(sqrt(x)*x)*f1*sin(s*x),x,0,infinity),
  fourier_sin2(1/(sqrt(~x)*~x^~a),~f1,~x) => 
		 int(1/(sqrt(x)*x^a)*f1*sin(s*x),x,0,infinity),
  fourier_sin2(~x^~a,~f1,~x) => int(x^a*f1*sin(s*x),x,0,infinity),
  fourier_sin2(~x,~f1,~x) => int(x*f1*sin(s*x),x,0,infinity),
  fourier_sin2(sqrt(~x),~f1,~x)=> int(sqrt(x)*f1*sin(s*x),x,0,infinity),
  fourier_sin2(sqrt(~x)*~x,~f1,~x) =>
		 int(sqrt(x)*x*f1*sin(s*x),x,0,infinity),
  fourier_sin2(sqrt(~x)*~x^~a,~f1,~x) =>
		 int(sqrt(x)*x^a*f1*sin(s*x),x,0,infinity),
  fourier_sin2(~b,~f1,~x) => int(b*f1*sin(s*x),x,0,infinity),
  fourier_sin2(~f1,~x) => int(f1*sin(s*x),x,0,infinity)
};

let fourier_sin2_rules;

fourier_cos2_rules :=

{ fourier_cos2(1/~x,~f1,~x) => int(1/x*f1*cos(s*x),x,0,infinity),
  fourier_cos2(1/~x^(~a),~f1,~x) => int(1/x^a*f1*cos(s*x),x,0,infinity),
  fourier_cos2(1/sqrt(~x),~f1,~x) => 
		int(1/sqrt(x)*f1*cos(s*x),x,0,infinity),
  fourier_cos2(1/(sqrt(~x)*~x),~f1,~x) => 
		int(1/(sqrt(x)*x)*f1*cos(s*x),x,0,infinity),
  fourier_cos2(1/(sqrt(~x)*~x^~a),~f1,~x) => 
		int(1/(sqrt(x)*x^a)*f1*cos(s*x),x,0,infinity),
  fourier_cos2(~x^~a,~f1,~x) => int(x^a*f1*cos(s*x),x,0,infinity),
  fourier_cos2(~x,~f1,~x) => int(x*f1*cos(s*x),x,0,infinity),
  fourier_cos2(sqrt(~x),~f1,~x)=> int(sqrt(x)*f1*cos(s*x),x,0,infinity),
  fourier_cos2(sqrt(~x)*~x,~f1,~x) => 
		       int(sqrt(x)*x*f1*cos(s*x),x,0,infinity),
  fourier_cos2(sqrt(~x)*~x^~a,~f1,~x) => 
		       int(sqrt(x)*x^a*f1*cos(s*x),x,0,infinity),
  fourier_cos2(~b,~f1,~x) => int(b*f1*cos(s*x),x,0,infinity),
  fourier_cos2(~f1,~x) => int(f1*cos(s*x),x,0,infinity)
};

let fourier_cos2_rules;

>>;

endmodule;
end;



