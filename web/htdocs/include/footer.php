<footer class="<?= isset($footer_class) ? $footer_class : 'col-xl-3' ?>">
    <div class="sticky-top">
        <hr class="d-display d-xl-none" />
        <p>
            Page last modified on
            <?= date('l jS F Y', filemtime($_SERVER['SCRIPT_FILENAME'])) ?>.
        </p>
        <p>
            All information available through this web site is
            Copyright &copy; Anthony C. Hearn and the
            <a href="https://sourceforge.net/p/reduce-algebra/_members/">REDUCE
                developers</a> 2009&ndash;
            <?= date('Y') ?>. All Rights Reserved.
        </p>
        <p>
            Please report broken links (both in-coming and out-going), other
            errors or suggestions for improvement to
            <a href="https://sites.google.com/site/fjwcentaur/feedback">webmaster</a>.
        </p>
        <p>
            This web site is built using <a href="https://www.php.net/">PHP</a>
            and <a href="https://getbootstrap.com/">Bootstrap</a>.
            It should be
            <a href="javascript:void(location.href =
                     'https://html5.validator.nu/?doc='+encodeURIComponent(location.href))"
                style="color:black;text-decoration:none;">valid</a>
            <!-- target="_blank" or holding down ctrl causes this to fail! -->
            <a href="https://en.wikipedia.org/wiki/XHTML#XHTML5">XHTML5</a>.
            Microsoft Internet Explorer does not display this web site
            correctly; please use a current web browser.
        </p>
        <div style="display: flex; flex-wrap: wrap-reverse; justify-content: space-around;">
            <!-- Begin SF Tag -->
            <div class="sf-root" data-id="248416" data-badge="oss-open-source-excellence-white"
                data-metadata="achievement=oss-open-source-excellence" style="width:125px">
                <a href="https://sourceforge.net/projects/reduce-algebra/" target="_blank">REDUCE</a>
            </div>
            <script>(function () {
                    var sc = document.createElement('script'); sc.type = 'text/javascript';
                    sc.async = true; sc.src = 'https://b.sf-syn.com/badge_js?sf_id=248416';
                    var p = document.getElementsByTagName('script')[0]; p.parentNode.insertBefore(sc, p);
                })();
            </script>
            <!-- End SF Tag -->
            <a href="https://www.mathjax.org">
                <img title="Powered by MathJax" src="https://www.mathjax.org/badge/badge.gif"
                    alt="Powered by MathJax" />
            </a>
        </div>
    </div>
</footer>

</div>
</div>

<!-- Bootstrap JavaScript bundle with Popper -->
<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.2.0/dist/js/bootstrap.bundle.min.js"
    integrity="sha384-A3rJD856KowSb7dwlZdYEkO39Gagi7vIsF0jrRAoQmDKKtQBHUuLZ9AsSv4jD4Xa"
    crossorigin="anonymous"></script>
