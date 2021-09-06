 // truy xuat cai nut

 // truoc khi truy xuat phai document ready


document.addEventListener("DOMContentLoaded", function(){

    var nut = document.getElementById('nut1');
    var khoi = document.getElementsByClassName('card');
    console.log(khoi[0])

    // go su kien click

    nut.onclick = function() {
        khoi[0].classList.toggle('diphai');
    }

}, false)



