module f5stat;
% f5 statistics. Collect and print statistics about Groebner basis computation
% with each call to f5.

revision('f5stat, "$Id$");

copyright('f5stat, "(c) 2022 A. Demin, T. Sturm, MPI Informatics, Germany");

% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions
% are met:
%
%    * Redistributions of source code must retain the relevant
%      copyright notice, this list of conditions and the following
%      disclaimer.
%    * Redistributions in binary form must reproduce the above
%      copyright notice, this list of conditions and the following
%      disclaimer in the documentation and/or other materials provided
%      with the distribution.
%
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
% "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
% LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
% A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
% OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
% SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
% LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
% DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
% THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
% (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
% OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% All information is stored in several global variables,
% and is updated using the functions from the interface

fluid '(stat_nCurrentIndex!*    stat_nModuleIndices!*
        stat_nAllReductions!*   stat_nZeroReductions!*
        stat_nNormalFormCalls!* stat_nDegreeRange!*
        stat_nCriticalPairs!*   stat_initialMinDegree!*);

% stat_nCurrentIndex!* - the current index in the module
% (the mathematical module, namely, the index `i` from the `core_incrementalBasis`)
% initial stat_nCurrentIndex!* is always 0, and the last
% stat_nCurrentIndex!* always equals to tstat_nModuleIndices!*
stat_nCurrentIndex!*    := 0;
stat_nModuleIndices!*   := 0;

% stat_nAllReductions!* - a vector, the i-th element in the vector
% is an integer that corresponds to the total number of polynomials
% reduced in the core_reduction function on the i-th call to `core_incrementalBasis`.
% So, all entries in stat_nAllReductions!* sum up to
% the total number of polynomials reduced
stat_nAllReductions!*   := nil;

% stat_nZeroReductions!* - a vector, the i-th element in the vector
% is an integer that corresponds to the number of polynomials REDUCED TO ZERO
% in the core_reduction function on the i-th call of `core_incrementalBasis`.
stat_nZeroReductions!*  := nil;

% stat_nNormalFormCalls!* - a vector of integers, the i-th element
% in the vector corresponds to the number of calls to a normal form
% function from `core_reduction` on the i-th call of `core_incrementalBasis`.
% Note that these elements can be larger than respective elements from
% the stat_nAllReductions!* vector. The reason is that for one reduction
% the normal form function can be called multiple times
stat_nNormalFormCalls!* := nil;

% stat_nDegreeRange!* - a vector of DottedPairs, the i-th pair
% indicates the range of degrees of critical pairs encountered
% on the i-th module index. For example, pair 3 . 8 would mean
% that the smallest encountered degree was 3, and the largest was 8
stat_nDegreeRange!*     := nil;

stat_nCriticalPairs!*   := nil;

% To initialize the minimal degree with a "very large number"
fluid '(stat_initialMinDegree!*);
stat_initialMinDegree!* := 10000;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Statistics manipulation interface

% Discards all collected info and initializes
% global variables for `m` future calls of `core_incrementalBasis`
asserted procedure stat_init(m: Integer);
  <<
    stat_nCurrentIndex!*    := 0;
    stat_nModuleIndices!*   := m;
    stat_nAllReductions!*   := mkvect(m);
    stat_nZeroReductions!*  := mkvect(m);
    stat_nNormalFormCalls!* := mkvect(m);
    stat_nDegreeRange!*     := mkvect(m);
    stat_nCriticalPairs!*   := mkvect(m);
    for i := 0:m do <<
      putv(stat_nAllReductions!*, i, 0);
      putv(stat_nZeroReductions!*, i, 0);
      putv(stat_nNormalFormCalls!*, i, 0);
      putv(stat_nCriticalPairs!*, i, 0);
      putv(stat_nDegreeRange!*, i, stat_initialMinDegree!* . 0)
    >>
  >>;

% Increments the number of polynomial reductions to zero by one
asserted procedure stat_incrementZeroReductions();
  putv(stat_nZeroReductions!*,
       stat_nCurrentIndex!*,
       getv(stat_nZeroReductions!*, stat_nCurrentIndex!*) + 1);

% Increments the module index
asserted procedure stat_updateModuleIndex();
  stat_nCurrentIndex!* := stat_nCurrentIndex!* + 1;

% Increments the module index
asserted procedure stat_updatePairs(p: Integer);
  putv(
    stat_nCriticalPairs!*,
    stat_nCurrentIndex!*,
    getv(stat_nCriticalPairs!*, stat_nCurrentIndex!*) + p
  );

% Updates statistics with the data from the main loop of core_incrementalBasis:
%  . d is the degree of selected critical pairs, it updates stat_nDegreeRange!*
%  . p
asserted procedure stat_updateIncremental(d: Integer, p: Integer);
  begin scalar degreeRange, i;
    degreeRange := getv(stat_nDegreeRange!*, stat_nCurrentIndex!*);
    if car degreeRange > d then
      car degreeRange := d;
    if cdr degreeRange < d then
      cdr degreeRange := d;
    i := stat_nCurrentIndex!*;
    putv(stat_nCriticalPairs!*, i, getv(stat_nCriticalPairs!*, i) + p)
  end;

% Updates statistics with the polynomial reductions data
asserted procedure stat_updateReductions(newAllReductions: Integer,
                                          newNormalForms: Integer);
  begin integer i;
    i := stat_nCurrentIndex!*;
    newAllReductions := getv(stat_nAllReductions!*, i) + newAllReductions;
    newNormalForms   := getv(stat_nNormalFormCalls!*, i) + newNormalForms;
    putv(stat_nAllReductions!*, i, newAllReductions);
    putv(stat_nNormalFormCalls!*, i, newNormalForms)
  end;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% String manipulation for pretty printing

% Pads list `s` with spaces from both sides until its length
% is equal to `width`. For example, for width = 7,
%   {"1", "2", "3"}  --> {" ", " ", "1", "2", "3", " ", " "}
asserted procedure stat_paveList(s: List, width: Integer): List;
  <<
    while length(s) < width do <<
      if evenp length(s) then
        s := nconc(s, {" "})
      else
        push(" ", s)
    >>;
    s
  >>;

% Construct a string from the list `s` by concatenating list
% elements recursively. Converting each element, that is not a list itself,
% to a String. For example, stat_joinList({2, "4", {5}}) is "245"
asserted procedure stat_joinList(s: List): String;
  if null s then
    ""
  else if listp (car s) then
    concat(stat_joinList(car s), stat_joinList(cdr s))
  else
    concat(ioto_sprin2(car s), stat_joinList(cdr s));

% Prints collected f5 statistics in the table in the following format:
%
% ---------------------------------------------------------------------
% | # i | # reductions | # zero reductions | # normal forms | degrees |
% ---------------------------------------------------------------------
% |  i1 |      x1      |         x3        |       x5       | x7 - x8 |
% |  i2 |      x2      |         x4        |       x6       | x9 - x10|
% ---------------------------------------------------------------------
%  Total       X1                X2                X3
%
% Where columns labels stand for
%    # i - the module index (the signature index)
%    # reductions - the number of polynomials reduced
%    # zero reductions - the number of polynomials reduced to zero
%    # normal forms - the number of normal forms computed
%    degree range - the minimal degree and the maximal degree of a critical pair
% Total:
%   Xi = sum xi for xi in this column
asserted procedure stat_print();
  begin scalar header0, header1, header2, footer,
                spaces, tmp, degsep, degs, line, colsep;
        integer idx, red1, red2, nf, mindeg, maxdeg, ps,
                totalAllReductions, totalZeroReductions,
                totalNormalForms, totalCriticalPairs;
    % headers of our table, defining 5 columns, from left to right:
    % the module index, the number of reduced polynomials,
    % the number of polynomials reduced to zero,
    % the number of normal forms computed,
    % the range of critical pair degrees
    header0 := "-------------------------------------------------------------------------------";
    header1 := "| # i | # pairs | # reductions | # zero reductions | # normal forms | degrees |";
    header2 := "-------------------------------------------------------------------------------";
    footer  := header2;
    % widths of table columns
    spaces  := {5, 9, 14, 19, 16, 7};
    % degree separator, and column separator
    degsep  := " - ";
    colsep  := "|";
    % print table headers
    prin2t header0;
    prin2t header1;
    prin2t header2;
    % print table data, one module index - one line
    for i := 1:stat_nModuleIndices!* do <<
      tmp  := spaces;
      idx  := stat_paveList({i}, pop(tmp));
      ps   := stat_paveList(explode(getv(stat_nCriticalPairs!*, i)), pop(tmp));
      red1 := stat_paveList(explode(getv(stat_nAllReductions!*, i)), pop(tmp));
      red2 := stat_paveList(explode(getv(stat_nZeroReductions!*, i)), pop(tmp));
      nf   := stat_paveList(explode(getv(stat_nNormalFormCalls!*, i)), pop(tmp));
      mindeg . maxdeg := getv(stat_nDegreeRange!*, i);
      if not (mindeg = stat_initialMinDegree!*) then
        degs := nconc(explode(mindeg), degsep . explode(maxdeg))
      else
        degs := {degsep};
      degs := stat_paveList(degs, pop(tmp));
      line := stat_joinList({colsep, idx,
                             colsep, ps,
                             colsep, red1,
                             colsep, red2,
                             colsep, nf,
                             colsep, degs,
                             colsep});
      prin2t line;
    >>;
    % calculate totals
    for i := 1:stat_nModuleIndices!* do <<
      totalAllReductions  := getv(stat_nAllReductions!*, i) + totalAllReductions;
      totalZeroReductions := getv(stat_nZeroReductions!*, i) + totalZeroReductions;
      totalNormalForms    := getv(stat_nNormalFormCalls!*, i) + totalNormalForms;
      totalCriticalPairs  := getv(stat_nCriticalPairs!*, i) + totalCriticalPairs
    >>;
    % print last lines of the table
    prin2t footer;
    prin2t stat_joinList({
      stat_paveList({"Total"}, pop(spaces)-2),
      stat_paveList(explode(totalCriticalPairs), pop(spaces)),
      stat_paveList(explode(totalAllReductions), pop(spaces)+2),
      stat_paveList(explode(totalZeroReductions), pop(spaces)),
      stat_paveList(explode(totalNormalForms), pop(spaces)+2)
    })
  end;

endmodule;  % end of module f5stat

end;  % of file
