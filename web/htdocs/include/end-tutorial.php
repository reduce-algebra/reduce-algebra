</div><!-- opened in begin-body.php -->

<?php
include '../include/footer.php';
/*
 * Required markup, with a <div class="accordion-item"> for each problem/solution pair:
 * <div class="accordion" id="P_S_accordion">
 *     ...
 *     <div class="accordion-item">
 *         <!-- Problem N -->
 *         <h2 class="accordion-header" id="headingN">
 *             <button class="accordion-button collapsed" type="button" data-bs-toggle="collapse" data-bs-target="#collapseN"
 *                     aria-expanded="false" aria-controls="collapseN">
 *                 Problem N+1
 *             </button>
 *         </h2>
 *         Problem text...
 *         <!-- Solution N -->
 *         <div id="collapseN" class="accordion-collapse collapse" aria-labelledby="headingN" data-bs-parent="#P_S_accordion">
 *             <div class="accordion-body">
 *                 <h5>REDUCE solution</h5>
 *                 <pre>Solution text...</pre>
 *             </div>
 *         </div>
 *     </div>
 *     ...
 * </div>
 */
?>

<!-- The slim version of jQuery does not include ajax (or effects)
     and I use ajax on the documentation page! -->
<script src="https://code.jquery.com/jquery-3.6.0.min.js"
        integrity="sha256-/xUj+3OJU5yExlq6GSYGSHk7tPXikynS7ogEvDej/m4="
        crossorigin="anonymous"></script>
<script>
 $("#P_S_accordion > div") // Complete problem markup:
     .addClass("accordion-item").prepend(function(n){
         return `<h2 class="accordion-header" id="heading${n}">
<button class="accordion-button collapsed" type="button" data-bs-toggle="collapse" data-bs-target="#collapse${n}"
aria-expanded="false" aria-controls="collapse${n}">
Problem ${n+1}
</button>
</h2>`;
     });

 $("#P_S_accordion > div > pre") // Complete solution markup:
     .wrap(function(n){
         return `<div id="collapse${n}" class="accordion-collapse collapse" aria-labelledby="heading${n}" data-bs-parent="#P_S_accordion">
<div class="accordion-body"></div></div>`;
     })
     .parent().prepend('<h5>REDUCE solution</h5>');
</script>

<!-- Use the same URL as used for the HTML manual for cache efficiency. -->
<script id="MathJax-script" src="https://cdn.jsdelivr.net/npm/mathjax@3/es5/tex-chtml-full.js"></script>

</body>
</html>
