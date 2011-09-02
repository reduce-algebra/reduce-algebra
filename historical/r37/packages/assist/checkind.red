module checkind;

% This modules contains procedures to detect indices, 
% check the coherence (variance) of expressions (sum), (free indices)
% declares repeated (1 cov and 1 cont) indices as dummy.

global '(spaces!*);

fluid('(dummy_id!* g_dvnames epsilon!*)); 


symbolic procedure split_free_dum_ids(ltens);
% ltens est la liste qui provient de sep_tens_from_other.
% result of all_index_lst is the full set of indices.
% verify the consistency of the list of dummy indices.
% output the list (<ordered set of free indices>,<set of dummy indices>) 
  begin scalar ind,dumlist,freelist;
   ind:=split_cov_cont_ids all_index_lst ltens; 
   ind:=list(clean_numid car ind,clean_numid cadr ind);
   dumlist:=intersection(car ind,cadr ind);   
   verify_tens_ids ind where dummy_id!*=dumlist; 
     % construct the list of covariant FREE indices:
   freelist:=for each y in setdiff(car ind,dumlist)
                                        collect lowerind y;
   % add to it the list of contravariant FREE indices
    freelist:=append(freelist,setdiff(cadr ind,dumlist));
  return list(ordn freelist,dumlist);
 end;

symbolic procedure check_ids(sf);
% check the variance consistency of the input SF  
  begin  scalar dumlist, freelist, y;
  freelist:='undefined;
  while not domainp (sf) do
    <<
      y:=sep_tens_from_other (lt sf .+ nil);
      if length car y >=1
        then 
          << % There are tensors, get dummy and free indices, compare 
            y:= split_free_dum_ids car y;
            if freelist='undefined then freelist:=car y
              else
            if freelist neq car y then rerror(cantens,11,
                    list("mismatch in free indices : ",
                    list(car y, freelist)));
            dumlist:= union(dumlist, cadr y)
          >>
        else
       % no FREE indices
      if freelist then
           if freelist = 'undefined then freelist:=nil
             else rerror(cantens,11,"scalar added with tensor(s)");
       sf:=red sf
    >>;
  if freelist neq 'undefined then
    if (y:=repeats freelist) and extract_dummy_ids y then
      rerror(cantens,12,list("wrong use of indices",y));
  return  
     if freelist='undefined or null freelist then list(nil,dumlist)
       else
     if sf then  rerror(cantens,12,"scalar added with tensor(s)")
       else  list(freelist,dumlist)        
end;

endmodule;

end;
