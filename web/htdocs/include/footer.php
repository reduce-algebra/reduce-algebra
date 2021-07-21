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
                developers</a> 2009&ndash;<?= date('Y') ?>.  All Rights
            Reserved.
        </p>
        <p>
            Microsoft Internet Explorer does not display this web site
            correctly; please use a current web browser.
        </p>
        <p>
            Please report broken links (both in-coming and out-going), other
            errors or suggestions for improvement to
            <a href="https://sites.google.com/site/fjwcentaur/feedback">webmaster</a>.
        </p>
        <p>This web page should be
            <a href="javascript:void(location.href =
                     'https://html5.validator.nu/?doc='+encodeURIComponent(location.href))"
               style="color:black;text-decoration:none;">valid</a>
            <!-- target="_blank" or holding down ctrl causes this to fail! -->
            <a href="https://en.wikipedia.org/wiki/XHTML#XHTML5">XHTML5</a>.
        </p>
    </div>
</footer>

    </div>
    </div>

    <!-- Bootstrap JavaScript bundle with Popper -->
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js"
            integrity="sha384-MrcW6ZMFYlzcLA8Nl+NtUVF0sA7MsXsP1UyJoMp4YLEuNSfAP+JcXn/tWtIaxVXM" crossorigin="anonymous"></script>
