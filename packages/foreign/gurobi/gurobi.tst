lisp;

gurobi_newmodel(0, 2);

gurobi_addconstraintfast('geq, {-2, -2}, -3);
gurobi_addconstraintfast('geq, {1, 0}, 1);
gurobi_addconstraintfast('geq, {0, 1}, 1);

gurobi_updatemodel();
gurobi_dumpmodel();

gurobi_negconstr1();

gurobi_updatemodel();
gurobi_dumpmodel();

gurobi_optimize();

gurobi_freemodel();

gurobi_newmodel(0, 2);

gurobi_addconstraintfast('geq, {3, 2}, 1);
gurobi_addconstraintfast('geq, {2, 0}, 1);
gurobi_addconstraintfast('geq, {0, 2}, 1);

gurobi_updatemodel();

gurobi_optimize();

gurobi_freemodel();

gurobi_newmodel(2, 0);

gurobi_addconstraintfast('geq, {3, 2}, 1);
gurobi_addconstraintfast('geq, {2, 0}, 1);
gurobi_addconstraintfast('geq, {0, 2}, 1);

gurobi_updatemodel();

gurobi_optimize();

gurobi_freemodel();

end;  % of file
