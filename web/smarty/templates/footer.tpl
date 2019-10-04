{* Smarty *}
<footer class="{$class}">
  <div class="sticky-top">
    <hr class="d-display d-xl-none" />
    <p>Page last modified on {page_mod_date}.</p>
    <p>All information available through this web site is Copyright &copy; Anthony C. Hearn and the <a href="https://sourceforge.net/p/reduce-algebra/_members/">REDUCE developers</a> 2009&ndash;{$smarty.now|date_format:"%Y"}.  All Rights Reserved.</p>
    <p>Please report broken links (both in-coming and out-going), other errors or suggestions for improvement to the <a href="https://sourceforge.net/users/fjwright/">webmaster</a>.</p>
    <p>This web page should be
      <a href="javascript:void(location.href='https://html5.validator.nu/?doc='+encodeURIComponent(location.href))"
         {* target="_blank" or holding down ctrl causes this to fail! *}
         style="color:black;text-decoration:none;">valid</a>
      <a href="https://en.wikipedia.org/wiki/XHTML#XHTML5">XHTML5</a>.</p>
  </div>
</footer>
