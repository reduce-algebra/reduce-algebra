
(fluid '(bstack_exception_count bstack_exception_max))

(setq bstack_exception_count 0 )

(setq bstack_exception_max 15 )

(de bstackoverflow ()
  (setq bstack_exception_count (wplus2 1 bstack_exception_count ))
  (when (wgreaterp bstack_exception_count bstack_exception_max)
	(setq bstack_exception_count 0 )
  %      (channelprin2 errout* 
%			"***** Binding stack maximal exception terminating...")
  %      (channelterpi errout!*)
        (external_exit -1))
  (channelprin2 errout* "***** Binding stack overflow, restarting...")
  (channelwritechar errout* (char eol))
  (reset))

(de bstackunderflow ()
  (setq bstack_exception_count (wplus2 1 bstack_exception_count ))
  (when (wgreaterp bstack_exception_count bstack_exception_max)
        (setq bstack_exception_count 0 )
%        (channelprin2 errout* 
%			"***** Binding stack maximal exception terminating...")
%        (channelterpi errout!*)
        (external_exit -1))
  (channelprin2 errout* "***** Binding stack underflow, restarting...")
  (channelwritechar errout* (char eol))
  (reset))


