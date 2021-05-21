</div><!-- opened in begin-body.php -->

<?php
include '../include/footer.php';
/*
 * Required markup, with a <div class="card"> for each problem/solution pair:
 * <div class="accordion" id="P_S_accordion">
 *     <div class="card">
 *         <!-- Problem N -->
 *         <h4 class="card-header" id="headingN">
 *             Problem N+1
 *             <button class="btn btn-link collapsed" type="button"
 *                     data-toggle="collapse" data-target="#collapseN"
 *                     aria-expanded="false" aria-controls="collapseN">
 *                 Show/hide solution
 *             </button>
 *         </h4>
 *         <div class="card-body">
 *             Problem text...
 *         </div>
 *         <!-- Solution N -->
 *         <div id="collapseN" class="card-body collapse"
 *              aria-labelledby="headingN" data-parent="#P_S_accordion">
 *             <h5 class="card-title">REDUCE solution</h5>
 *             <pre class="card-text">Solution text...</pre>
 *         </div>
 *     </div>
 *     ...
 * </div>
 */
?>
<script>
    $("#P_S_accordion > div") // Complete problem markup:
    .addClass("card").find("div").addClass("card-body")
    .parent().prepend(function(n){
    return '<h4 class="card-header" id="heading' + n + '">Problem ' + (n+1) +
    '<button class="btn btn-link collapsed" type="button" data-toggle="collapse" data-target="#collapse' + n +
                    '" aria-expanded="false" aria-controls="collapse' + n + '">Show/hide solution</button></h4>';
    });
    $("#P_S_accordion > div > pre") // Complete solution markup:
    .addClass("card-text")
    .wrap(function(n){
    return '<div id="collapse' + n + '" class="card-body collapse" aria-labelledby="heading' + n + '" data-parent="#P_S_accordion">';
    })
    .parent().prepend('<h5 class="card-title">REDUCE solution</h5>');
</script>
<!-- Use the same URL as used for the HTML manual for cache efficiency. -->
<script id="MathJax-script" src="https://cdn.jsdelivr.net/npm/mathjax@3/es5/tex-chtml-full.js"></script>

</body>
</html>
