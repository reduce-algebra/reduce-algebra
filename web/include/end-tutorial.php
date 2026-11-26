</div><!-- opened in begin-body.php -->

<?php
include '../../include/footer.php';
?>

<script src="https://code.jquery.com/jquery-4.1.0.slim.min.js" integrity="sha256-0zreENPUQQKIbGBKGJ6WF289jZz9S3Y63TURDQTChnc=" crossorigin="anonymous"></script><script src="https://code.jquery.com/jquery-4.1.0.slim.min.js" integrity="sha256-0zreENPUQQKIbGBKGJ6WF289jZz9S3Y63TURDQTChnc=" crossorigin="anonymous"></script>
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
<script src="https://cdn.jsdelivr.net/npm/mathjax@4/tex-chtml.js"></script>

</body>
</html>
