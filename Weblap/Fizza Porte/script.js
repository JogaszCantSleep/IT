var numOrder;
var numin_1 = 0;
var numin_2 = 0;
var numin_3 = 0;
var numin_4 = 0;
var numin_5 = 0;
var numin_6 = 0;
var numin_7 = 0;
var numin_8 = 0;
var numin_9 = 0;
var numin_10 = 0;

var service_fee_value;
var delivery_fee_value;
var pizzas_price_value;
var final_price_value;
var service_fee;
var delivery_fee;
var pizzas_price;
var final_price;

var diyOrderList = [];

/* Default starts */

document.getElementById('numin_1').value = 0;
document.getElementById('numin_2').value = 0;
document.getElementById('numin_3').value = 0;
document.getElementById('numin_4').value = 0;
document.getElementById('numin_5').value = 0;
document.getElementById('numin_6').value = 0;
document.getElementById('numin_7').value = 0;
document.getElementById('numin_8').value = 0;
document.getElementById('numin_9').value = 0;
document.getElementById('numin_10').value = 0;

var imgPizza = document.querySelectorAll('.diy .container .pizza_board img');
var sizeValue;

if (window.innerWidth < 1100) {
    sizeValue = '85vw';
    document.getElementById('radio_size_50_label').style.border = '2px solid rgb(52, 202, 15)';
    document.getElementById('radio_size_50_label').style.scale = '1.03';
    document.getElementById('radio_size_50').checked = true;
    imgPizza.forEach(function (pizza) {
        pizza.style.height = sizeValue;
    });
}
else if (window.innerWidth > 1100) {
    sizeValue = '39vw';
    document.getElementById('radio_size_50_label').style.border = '2px solid rgb(52, 202, 15)';
    document.getElementById('radio_size_50_label').style.scale = '1.03';
    document.getElementById('radio_size_50').checked = true;
    imgPizza.forEach(function (pizza) {
        pizza.style.height = sizeValue;
    });
}

document.getElementById('radio_no_sauce_label').style.border = '2px solid rgb(52, 202, 15)';
document.getElementById('radio_no_sauce_label').style.scale = '1.03';
document.getElementById('radio_no_sauce').checked = true;

service_fee = document.getElementById('service_fee').innerHTML;
service_fee_value = 0 + ' $';
document.getElementById('service_fee').innerHTML = service_fee + service_fee_value;

delivery_fee = document.getElementById('delivery_fee').innerHTML;
delivery_fee_value = 0 + ' $';
document.getElementById('delivery_fee').innerHTML = delivery_fee + delivery_fee_value;

pizzas_price = document.getElementById('pizzas_price').innerHTML;
pizzas_price_value = 0 + ' $';
document.getElementById('pizzas_price').innerHTML = pizzas_price + pizzas_price_value;

final_price = document.getElementById('final_price').innerHTML;
final_price_value = 0 + ' $';
document.getElementById('final_price').innerHTML = final_price + final_price_value;

/* Function callings */

document.getElementById('check_cheese').onclick = checkCheese;
document.getElementById('check_corn').onclick = checkCorn;
document.getElementById('check_pepperoni').onclick = checkPepperoni;
document.getElementById('check_mushrooms').onclick = checkMushrooms;
document.getElementById('check_onions').onclick = checkOnions;
document.getElementById('check_pineapple').onclick = checkPineapple;
document.getElementById('check_ham').onclick = checkHam;
document.getElementById('check_spinach').onclick = checkSpinach;
document.getElementById('check_tomato').onclick = checkTomato;
document.getElementById('check_tuna').onclick = checkTuna;
document.getElementById('check_broccoli').onclick = checkBroccoli;
document.getElementById('check_olives').onclick = checkOlives;
document.getElementById('menu_order').onclick = orderFill;
document.getElementById('diy_order').onclick = diyOrder;
document.getElementById('clear_order').onclick = clearOrder;

/* Numin refresh */

function numinRefresh() {
    numin_1 = parseInt(document.getElementById('numin_1').value);
    numin_2 = parseInt(document.getElementById('numin_2').value);
    numin_3 = parseInt(document.getElementById('numin_3').value);
    numin_4 = parseInt(document.getElementById('numin_4').value);
    numin_5 = parseInt(document.getElementById('numin_5').value);
    numin_6 = parseInt(document.getElementById('numin_6').value);
    numin_7 = parseInt(document.getElementById('numin_7').value);
    numin_8 = parseInt(document.getElementById('numin_8').value);
    numin_9 = parseInt(document.getElementById('numin_9').value);
    numin_10 = parseInt(document.getElementById('numin_10').value);
}

/* Diy order processing */

function diyOrder() {
    diySize = [...document.querySelectorAll('.diy > .container > .select_container > .select_board > .size > .select input[type="radio"]')].find(radio => radio.checked)?.nextElementSibling?.innerHTML || '';
    diySauces = [...document.querySelectorAll('.diy > .container > .select_container > .select_board > .sauces > .select input[type="radio"]')].find(radio => radio.checked)?.nextElementSibling?.innerHTML || '';
    checkedToppings = document.querySelectorAll('.diy > .container > .select_container > .select_board > .toppings > .select input[type="checkbox"]:checked');
    diyToppings = Array.from(checkedToppings).map(checkbox => checkbox.nextElementSibling.textContent);

    var diyOrderItem = {
        size: diySize,
        sauce: diySauces,
        toppings: diyToppings
    }

    diyOrderList.push(diyOrderItem);
    orderFill();
}

/* Filling up the order site */

function orderFill() {
    numinRefresh();

    numOrder = numin_1 + numin_2 + numin_3 + numin_4 + numin_5 + numin_6 + numin_7 + numin_8 + numin_9 + numin_10 + diyOrderList.length;

    order_amount = document.getElementById('order_amount');

    order_amount.innerHTML = numOrder;

    if (numOrder > 0) {
        order_amount.style.display = 'block';
    }
    else {
        order_amount.style.display = 'none';
    }

    var menuDivCount = 0;

    for (let i = 0; i <= 10; i++) {
        if (window['numin_' + i] > 0) {
            menuDivCount++;
        }
    }

    var container = document.querySelector('.order_site .container');

    if (container.hasChildNodes()) {
        while (container.firstChild) {
            container.removeChild(container.firstChild);
        }
    }

    var f = 0;

    for (let i = 0; i < menuDivCount; i++) {
        f = i + 1;

        /* Creating elements */
        window['unit_' + f] = document.createElement("div");
        window['pizza_' + f] = document.createElement("img");
        window['unit_text_' + f] = document.createElement("div");
        window['title_' + f] = document.createElement("h1");
        window['toppings_' + f] = document.createElement("p");
        window['price_div_' + f] = document.createElement("div");
        window['price_' + f] = document.createElement("h2");

        /* Setting element attributes */
        window['unit_' + f].classList.add("unit", "unit_" + f);
        window['pizza_' + f].classList.add("pizza", "pizza_" + f);
        window['unit_text_' + f].classList.add("unit_text", "unit_text_" + f);
        window['title_' + f].classList.add("title", "title_" + f);
        window['toppings_' + f].classList.add("toppings", "toppings_" + f);
        window['price_div_' + f].classList.add("price_div", "price_div_" + f);
        window['price_' + f].classList.add("price", "price_" + f);

        /* Appending elements to their place */
        container.appendChild(window['unit_' + f]);
        window['unit_' + f].appendChild(window['pizza_' + f]);
        window['unit_' + f].appendChild(window['unit_text_' + f]);
        window['unit_text_' + f].appendChild(window['title_' + f]);
        window['unit_text_' + f].appendChild(window['toppings_' + f]);
        window['unit_text_' + f].appendChild(window['price_div_' + f]);
        window['price_div_' + f].appendChild(window['price_' + f]);
    }

    for (let j = 0; j < diyOrderList.length; j++) {

        f += 1;

        /* Creating elements */
        window['unit_' + f] = document.createElement("div");
        if (diyOrderList[j].sauce != 'No sauce') {
            for (let k = 0; k < (diyOrderList[j].toppings.length + 3); k++) {
                window['diy_' + f + '_topping_' + (k + 1)] = document.createElement("img");
            }
        }
        else {
            for (let k = 0; k < (diyOrderList[j].toppings.length + 2); k++) {
                window['diy_' + f + '_topping_' + (k + 1)] = document.createElement("img");
            }
        }
        window['unit_text_' + f] = document.createElement("div");
        window['title_' + f] = document.createElement("h1");
        window['toppings_' + f] = document.createElement("p");
        window['price_div_' + f] = document.createElement("div");
        window['price_' + f] = document.createElement("h2");

        /* Setting element attributes */
        window['unit_' + f].classList.add("unit", "unit_" + f);
        if (diyOrderList[j].sauce != 'No sauce') {
            for (let k = 0; k < (diyOrderList[j].toppings.length + 3); k++) {
                window['diy_' + f + '_topping_' + (k + 1)].classList.add("topping", 'topping_' + (k + 1), 'diy_' + f + '_topping_' + (k + 1));
            }
        }
        else {
            for (let k = 0; k < (diyOrderList[j].toppings.length + 2); k++) {
                window['diy_' + f + '_topping_' + (k + 1)].classList.add("topping", 'diy_' + f + '_topping_' + (k + 1));
            }
        }
        window['unit_text_' + f].classList.add("unit_text", "unit_text_" + f);
        window['title_' + f].classList.add("title", "title_" + f);
        window['toppings_' + f].classList.add("toppings", "toppings_" + f);
        window['price_div_' + f].classList.add("price_div", "price_div_" + f);
        window['price_' + f].classList.add("price", "price_" + f);

        /* Appending elements to their place */
        container.appendChild(window['unit_' + f]);
        if (diyOrderList[j].sauce != 'No sauce') {
            for (let k = 0; k < (diyOrderList[j].toppings.length + 3); k++) {
                window['unit_' + f].appendChild(window['diy_' + f + '_topping_' + (k + 1)]);
            }
        }
        else {
            for (let k = 0; k < (diyOrderList[j].toppings.length + 2); k++) {
                window['unit_' + f].appendChild(window['diy_' + f + '_topping_' + (k + 1)]);
            }
        }
        window['unit_' + f].appendChild(window['unit_text_' + f]);
        window['unit_text_' + f].appendChild(window['title_' + f]);
        window['unit_text_' + f].appendChild(window['toppings_' + f]);
        window['unit_text_' + f].appendChild(window['price_div_' + f]);
        window['price_div_' + f].appendChild(window['price_' + f]);
    }

    childrenCount = 0;

    if (window['numin_1'] > 0) {
        childrenCount++;
        window['pizza_' + childrenCount].setAttribute("src", "./pics/margherita.png");
        window['title_' + childrenCount].innerHTML = 'Margherita';
        window['toppings_' + childrenCount].innerHTML = 'Tomato sauce, cheese';
        window['price_' + childrenCount].innerHTML = '6.30 $ x ' + window['numin_1'] + ' = ' + (window['numin_1'] * 6.30).toFixed(2) + ' $';
    }

    if (window['numin_2'] > 0) {
        childrenCount++;
        window['pizza_' + childrenCount].setAttribute("src", "./pics/hawaii.png");
        window['title_' + childrenCount].innerHTML = 'Hawaii';
        window['toppings_' + childrenCount].innerHTML = 'Tomato sauce, cheese, pineapple, onions, tomato';
        window['price_' + childrenCount].innerHTML = '6.90 $ x ' + window['numin_2'] + ' = ' + (window['numin_2'] * 6.90).toFixed(2) + ' $';
    }

    if (window['numin_3'] > 0) {
        childrenCount++;
        window['pizza_' + childrenCount].setAttribute("src", "./pics/hell.png");
        window['title_' + childrenCount].innerHTML = 'Hell';
        window['toppings_' + childrenCount].innerHTML = 'Tomato sauce, cheese, olive, tomato, hellfire sauce, carolina reaper';
        window['price_' + childrenCount].innerHTML = '7.20 $ x ' + window['numin_3'] + ' = ' + (window['numin_3'] * 7.20).toFixed(2) + ' $';
    }

    if (window['numin_4'] > 0) {
        childrenCount++;
        window['pizza_' + childrenCount].setAttribute("src", "./pics/bolognese.png");
        window['title_' + childrenCount].innerHTML = 'Bolognese';
        window['toppings_' + childrenCount].innerHTML = 'Tomato sauce, cheese, pepperoni, onions, bolognese sauce, spinach';
        window['price_' + childrenCount].innerHTML = '6.50 $ x ' + window['numin_4'] + ' = ' + (window['numin_4'] * 6.50).toFixed(2) + ' $';
    }

    if (window['numin_5'] > 0) {
        childrenCount++;
        window['pizza_' + childrenCount].setAttribute("src", "./pics/vegetarian.png");
        window['title_' + childrenCount].innerHTML = 'Vegetarian';
        window['toppings_' + childrenCount].innerHTML = 'Tomato sauce, cheese, olive, tomato, onion, spinach';
        window['price_' + childrenCount].innerHTML = '5.90 $ x ' + window['numin_5'] + ' = ' + (window['numin_5'] * 5.90).toFixed(2) + ' $';
    }

    if (window['numin_6'] > 0) {
        childrenCount++;
        window['pizza_' + childrenCount].setAttribute("src", "./pics/meat_lover.png");
        window['title_' + childrenCount].innerHTML = 'Meat Lover';
        window['toppings_' + childrenCount].innerHTML = 'Tomato sauce, cheese, pepperoni, onions, chicken, spinach';
        window['price_' + childrenCount].innerHTML = '7.80 $ x ' + window['numin_6'] + ' = ' + (window['numin_6'] * 7.80).toFixed(2) + ' $';
    }

    if (window['numin_7'] > 0) {
        childrenCount++;
        window['pizza_' + childrenCount].setAttribute("src", "./pics/cheezy.png");
        window['title_' + childrenCount].innerHTML = 'Cheezy';
        window['toppings_' + childrenCount].innerHTML = 'Tomato sauce, mozzarella, parmesan, olive, tomato, pepperoni, spinach';
        window['price_' + childrenCount].innerHTML = '7.60 $ x ' + window['numin_7'] + ' = ' + (window['numin_7'] * 7.60).toFixed(2) + ' $';
    }

    if (window['numin_8'] > 0) {
        childrenCount++;
        window['pizza_' + childrenCount].setAttribute("src", "./pics/pepperoni.png");
        window['title_' + childrenCount].innerHTML = 'Pepperoni';
        window['toppings_' + childrenCount].innerHTML = 'Tomato sauce, cheese, pepperoni, spinach';
        window['price_' + childrenCount].innerHTML = '7.90 $ x ' + window['numin_8'] + ' = ' + (window['numin_8'] * 7.90).toFixed(2) + ' $';
    }

    if (window['numin_9'] > 0) {
        childrenCount++;
        window['pizza_' + childrenCount].setAttribute("src", "./pics/nemo.png");
        window['title_' + childrenCount].innerHTML = 'Nemo';
        window['toppings_' + childrenCount].innerHTML = 'Tomato sauce, cheese, olive, spinach, tuna';
        window['price_' + childrenCount].innerHTML = '8.20 $ x ' + window['numin_9'] + ' = ' + (window['numin_9'] * 8.20).toFixed(2) + ' $';
    }

    if (window['numin_10'] > 0) {
        childrenCount++;
        window['pizza_' + childrenCount].setAttribute("src", "./pics/bbq.png");
        window['title_' + childrenCount].innerHTML = 'BBQ';
        window['toppings_' + childrenCount].innerHTML = 'Tomato sauce, cheese, mozzarella, pepperoni, olive, onions, spinach';
        window['price_' + childrenCount].innerHTML = '7.90 $ x ' + window['numin_10'] + ' = ' + (window['numin_10'] * 7.90).toFixed(2) + ' $';
    }

    for (let i = 0; i < diyOrderList.length; i++) {
        childrenCount++;
        window['diy_' + childrenCount + '_topping_' + 1].setAttribute("src", "./pics/diy/pizza.png");
        if (diyOrderList[i].sauce == 'No sauce') {
            for (let r = 0; r < diyOrderList[i].toppings.length; r++) {
                let pic = (diyOrderList[i].toppings[r]).toLowerCase();
                window['diy_' + childrenCount + '_topping_' + (r + 1 + 1)].setAttribute("src", "./pics/diy/" + pic + ".png");
            }
            window['diy_' + childrenCount + '_topping_' + (diyOrderList[i].toppings.length + 2)].setAttribute("src", "./pics/diy/slicing.png");
        }
        if (diyOrderList[i].sauce != 'No sauce') {
            pic = (diyOrderList[i].sauce).toLowerCase() + '_sauce';
            window['diy_' + childrenCount + '_topping_' + 2].setAttribute("src", "./pics/diy/" + pic + ".png");
            for (let r = 0; r < diyOrderList[i].toppings.length; r++) {
                let pic = (diyOrderList[i].toppings[r]).toLowerCase();
                window['diy_' + childrenCount + '_topping_' + (r + 1 + 2)].setAttribute("src", "./pics/diy/" + pic + ".png");
            }
            window['diy_' + childrenCount + '_topping_' + (diyOrderList[i].toppings.length + 3)].setAttribute("src", "./pics/diy/slicing.png");
        }
        window['title_' + childrenCount].innerHTML = 'Own Choice';
        if (diyOrderList[i].sauce == 'No sauce') {
            window['toppings_' + childrenCount].innerHTML = diyOrderList[i].sauce + ', ' + diyOrderList[i].toppings;
        }
        else {
            window['toppings_' + childrenCount].innerHTML = diyOrderList[i].sauce + ' sauce, ' + (diyOrderList[i].toppings).join(', ');
        }
        window['price_' + childrenCount].innerHTML = (((4 + (diyOrderList[i].toppings.length * 0.6)) / 2) * (Math.sqrt(parseInt(diyOrderList[i].size) / 10))).toFixed(2) + ' $';
    }

    service_fee_value = ((diyOrderList.length + numOrder) * 1.2);
    document.getElementById('service_fee').innerHTML = service_fee + service_fee_value.toFixed(2) + ' $';

    delivery_fee_value = ((diyOrderList.length + numOrder) * 0.45);
    document.getElementById('delivery_fee').innerHTML = delivery_fee + delivery_fee_value.toFixed(2) + ' $';

    var diyPrice = 0;

    for (let i = 0; i < diyOrderList.length; i++) {
        diyPrice += (((4 + (diyOrderList[i].toppings.length * 0.6)) / 2) * (Math.sqrt(parseInt(diyOrderList[i].size) / 10)));
    }

    console.log(diyPrice)

    pizzas_price_value = diyPrice + (numin_1 * 6.30) + (numin_2 * 6.90) + (numin_3 * 7.20) + (numin_4 * 6.50) + (numin_5 * 5.90) + (numin_6 * 7.80) + (numin_7 * 7.60) + (numin_8 * 7.90) + (numin_9 * 8.20) + (numin_10 * 7.90);
    document.getElementById('pizzas_price').innerHTML = pizzas_price + pizzas_price_value.toFixed(2) + ' $';

    final_price_value = (service_fee_value + delivery_fee_value + pizzas_price_value);
    document.getElementById('final_price').innerHTML = final_price + final_price_value.toFixed(2) + ' $';
}

/* Order clearing */

function clearOrder() {
    diyOrderList = [];

    var container = document.querySelector('.order_site .container');

    if (container.hasChildNodes()) {
        while (container.firstChild) {
            container.removeChild(container.firstChild);
        }
    }

    document.getElementById('numin_1').value = 0;
    document.getElementById('numin_2').value = 0;
    document.getElementById('numin_3').value = 0;
    document.getElementById('numin_4').value = 0;
    document.getElementById('numin_5').value = 0;
    document.getElementById('numin_6').value = 0;
    document.getElementById('numin_7').value = 0;
    document.getElementById('numin_8').value = 0;
    document.getElementById('numin_9').value = 0;
    document.getElementById('numin_10').value = 0;

    numinRefresh();

    numOrder = numin_1 + numin_2 + numin_3 + numin_4 + numin_5 + numin_6 + numin_7 + numin_8 + numin_9 + numin_10 + diyOrderList.length;

    order_amount = document.getElementById('order_amount');

    order_amount.innerHTML = numOrder;

    if (numOrder > 0) {
        order_amount.style.display = 'block';
    }
    else {
        order_amount.style.display = 'none';
    }

    document.getElementById('service_fee').innerHTML = service_fee + 0 + ' $';
    document.getElementById('delivery_fee').innerHTML = delivery_fee + 0 + ' $';
    document.getElementById('pizzas_price').innerHTML = pizzas_price + 0 + ' $';
    document.getElementById('final_price').innerHTML = final_price + 0 + ' $';

    document.querySelectorAll('.diy input[type="checkbox"]').forEach(checkbox => {
        checkbox.checked = false;
    });

    document.querySelectorAll('.diy input[type="radio"]').forEach(radio => {
        radio.checked = false;
    });

    document.getElementById('radio_size_20_label').style.border = '';
    document.getElementById('radio_size_20_label').style.scale = '';

    document.getElementById('radio_size_30_label').style.border = '';
    document.getElementById('radio_size_30_label').style.scale = '';

    document.getElementById('radio_size_40_label').style.border = '';
    document.getElementById('radio_size_40_label').style.scale = '';

    document.getElementById('radio_size_50_label').style.border = '';
    document.getElementById('radio_size_50_label').style.scale = '';

    checkAll();

    if (window.innerWidth < 1100) {
        sizeValue = '85vw';
        document.getElementById('radio_size_50_label').style.border = '2px solid rgb(52, 202, 15)';
        document.getElementById('radio_size_50_label').style.scale = '1.03';
        document.getElementById('radio_size_50_label').pointerEvents = 'none';
        imgPizza.forEach(function (pizza) {
            pizza.style.height = sizeValue;
        });
    }
    else if (window.innerWidth > 1100) {
        sizeValue = '39vw';
        document.getElementById('radio_size_50_label').style.border = '2px solid rgb(52, 202, 15)';
        document.getElementById('radio_size_50_label').style.scale = '1.03';
        document.getElementById('radio_size_50_label').pointerEvents = 'none';
        imgPizza.forEach(function (pizza) {
            pizza.style.height = sizeValue;
        });
    }

    document.getElementById('radio_no_sauce_label').style.border = '2px solid rgb(52, 202, 15)';
    document.getElementById('radio_no_sauce_label').style.scale = '1.03';
    document.getElementById('radio_no_sauce_label').pointerEvents = 'none';
}

/* Order site */

document.getElementById('cart_btn').onclick = ordersiteVisibility;

function ordersiteVisibility() {
    order_site = document.getElementById('order_site');
    var body = document.body;

    if (order_site.style.display == "block") {
        order_site.style.opacity = 0;

        setTimeout(function () {
            order_site.style.display = "none";
        }, 200);
        body.style.overflow = "auto";
    }
    else {
        order_site.style.display = "block";
        setTimeout(function () {
            order_site.style.opacity = 1;
        }, 1);
        body.style.overflow = "hidden";
    }
}

/* Always-on resize */

window.onresize = windowSize;

function windowSize() {
    if (window.innerWidth < 1100) {
        if (document.getElementById('radio_size_20').checked) {
            sizeValue = '34vw';
        }
        else if (document.getElementById('radio_size_30').checked) {
            sizeValue = '51vw';
        }
        else if (document.getElementById('radio_size_40').checked) {
            sizeValue = '68vw';
        }
        else if (document.getElementById('radio_size_50').checked) {
            sizeValue = '85vw';
        }
        else {
            sizeValue = '85vw';
        }
        imgPizza.forEach(function (pizza) {
            pizza.style.height = sizeValue;
        });
    }
    else {
        if (document.getElementById('radio_size_20').checked) {
            sizeValue = '15.6vw';
        }
        else if (document.getElementById('radio_size_30').checked) {
            sizeValue = '23.4vw';
        }
        else if (document.getElementById('radio_size_40').checked) {
            sizeValue = '31.2vw';
        }
        else if (document.getElementById('radio_size_50').checked) {
            sizeValue = '39vw';
        }
        else {
            sizeValue = '39vw';
        }
        imgPizza.forEach(function (pizza) {
            pizza.style.height = sizeValue;
        });
    }
}

/* Sidebar */

var sidebar = document.getElementById('sidebar');
var ham_menu = document.getElementById('ham_menu');

document.getElementById('ham_menu').onclick = sideBar;

function sideBar() {
    var body = document.body;

    if (sidebar.style.left === "0%") {
        sidebar.style.left = "-120%";
        ham_menu.style.background = "";
        ham_menu.style.fill = "";
        ham_menu.style.boxShadow = "";
        document.getElementById('cart').style.opacity = 1;
        body.style.overflow = "auto";
    }
    else {
        sidebar.style.left = "0%";
        ham_menu.style.backgroundColor = "white";
        ham_menu.style.fill = "black";
        ham_menu.style.boxShadow = "0 0 10px 2px white";
        document.getElementById('cart').style.opacity = 0;
        body.style.overflow = "hidden";
    }
};

/* Closing links */

var sideLinks = document.querySelectorAll('.side_links');

sideLinks.forEach(function (link) {
    link.onclick = sidebarClosed;
});

/* Closed sidebar */

function sidebarClosed() {
    document.getElementById('sidebar').style.left = "-100%";
    ham_menu.style.background = "none";
    ham_menu.style.fill = "white";
    ham_menu.style.boxShadow = "none";
    document.getElementById('cart').style.opacity = 1;
};

/* Reset pizza */

document.getElementById('pizza_reset').onclick = unCheck;


function unCheck() {
    document.querySelectorAll('.diy input[type="checkbox"]').forEach(checkbox => {
        checkbox.checked = false;
    });

    document.querySelectorAll('.diy input[type="radio"]').forEach(radio => {
        radio.checked = false;
    });

    document.getElementById('radio_size_20_label').style.border = '';
    document.getElementById('radio_size_20_label').style.scale = '';

    document.getElementById('radio_size_30_label').style.border = '';
    document.getElementById('radio_size_30_label').style.scale = '';

    document.getElementById('radio_size_40_label').style.border = '';
    document.getElementById('radio_size_40_label').style.scale = '';

    document.getElementById('radio_size_50_label').style.border = '';
    document.getElementById('radio_size_50_label').style.scale = '';

    checkAll();

    if (window.innerWidth < 1100) {
        sizeValue = '85vw';
        document.getElementById('radio_size_50_label').style.border = '2px solid rgb(52, 202, 15)';
        document.getElementById('radio_size_50_label').style.scale = '1.03';
        document.getElementById('radio_size_50_label').pointerEvents = 'none';
        imgPizza.forEach(function (pizza) {
            pizza.style.height = sizeValue;
        });
    }
    else if (window.innerWidth > 1100) {
        sizeValue = '39vw';
        document.getElementById('radio_size_50_label').style.border = '2px solid rgb(52, 202, 15)';
        document.getElementById('radio_size_50_label').style.scale = '1.03';
        document.getElementById('radio_size_50_label').pointerEvents = 'none';
        imgPizza.forEach(function (pizza) {
            pizza.style.height = sizeValue;
        });
    }

    document.getElementById('radio_no_sauce_label').style.border = '2px solid rgb(52, 202, 15)';
    document.getElementById('radio_no_sauce_label').style.scale = '1.03';
    document.getElementById('radio_no_sauce_label').pointerEvents = 'none';
}

/* Check all */

function checkAll() {
    reSize();
    checkSauce();
    checkCheese();
    checkCorn();
    checkPepperoni();
    checkMushrooms();
    checkOnions();
    checkPineapple();
    checkHam();
    checkSpinach();
    checkTomato();
    checkTuna();
    checkBroccoli();
    checkOlives();
}

/* Pizza resize */

function reSize() {
    if (window.innerWidth < 1100) {
        sizeValue = '85vw';
        imgPizza.forEach(function (pizza) {
            pizza.style.height = sizeValue;
        });
    }
    else {
        sizeValue = '39vw';
        imgPizza.forEach(function (pizza) {
            pizza.style.height = sizeValue;
        });
    }
}

/* Size */

document.querySelectorAll('.size_select').forEach(function (radio_size) {
    radio_size.addEventListener('click', checkSize);
});

function checkSize() {
    if (window.innerWidth < 1100) {
        document.getElementById('radio_size_20_label').style.border = '';
        document.getElementById('radio_size_20_label').style.scale = '';

        document.getElementById('radio_size_30_label').style.border = '';
        document.getElementById('radio_size_30_label').style.scale = '';

        document.getElementById('radio_size_40_label').style.border = '';
        document.getElementById('radio_size_40_label').style.scale = '';

        document.getElementById('radio_size_50_label').style.border = '';
        document.getElementById('radio_size_50_label').style.scale = '';

        if (document.getElementById('radio_size_20').checked) {
            sizeValue = '34vw';
            document.getElementById('radio_size_20_label').style.border = '2px solid rgb(52, 202, 15)';
            document.getElementById('radio_size_20_label').style.scale = '1.03';
        }
        else if (document.getElementById('radio_size_30').checked) {
            sizeValue = '51vw';
            document.getElementById('radio_size_30_label').style.border = '2px solid rgb(52, 202, 15)';
            document.getElementById('radio_size_30_label').style.scale = '1.03';
        }
        else if (document.getElementById('radio_size_40').checked) {
            sizeValue = '68vw';
            document.getElementById('radio_size_40_label').style.border = '2px solid rgb(52, 202, 15)';
            document.getElementById('radio_size_40_label').style.scale = '1.03';
        }
        else if (document.getElementById('radio_size_50').checked) {
            sizeValue = '85vw';
            document.getElementById('radio_size_50_label').style.border = '2px solid rgb(52, 202, 15)';
            document.getElementById('radio_size_50_label').style.scale = '1.03';
        }
        imgPizza.forEach(function (pizza) {
            pizza.style.height = sizeValue;
        });
    }
    else {
        document.getElementById('radio_size_20_label').style.border = '';
        document.getElementById('radio_size_20_label').style.scale = '';

        document.getElementById('radio_size_30_label').style.border = '';
        document.getElementById('radio_size_30_label').style.scale = '';

        document.getElementById('radio_size_40_label').style.border = '';
        document.getElementById('radio_size_40_label').style.scale = '';

        document.getElementById('radio_size_50_label').style.border = '';
        document.getElementById('radio_size_50_label').style.scale = '';

        if (document.getElementById('radio_size_20').checked) {
            sizeValue = '15.6vw';
            document.getElementById('radio_size_20_label').style.border = '2px solid rgb(52, 202, 15)';
            document.getElementById('radio_size_20_label').style.scale = '1.03';
        }
        else if (document.getElementById('radio_size_30').checked) {
            sizeValue = '23.4vw';
            document.getElementById('radio_size_30_label').style.border = '2px solid rgb(52, 202, 15)';
            document.getElementById('radio_size_30_label').style.scale = '1.03';
        }
        else if (document.getElementById('radio_size_40').checked) {
            sizeValue = '31.2vw';
            document.getElementById('radio_size_40_label').style.border = '2px solid rgb(52, 202, 15)';
            document.getElementById('radio_size_40_label').style.scale = '1.03';
        }
        else if (document.getElementById('radio_size_50').checked) {
            sizeValue = '39vw';
            document.getElementById('radio_size_50_label').style.border = '2px solid rgb(52, 202, 15)';
            document.getElementById('radio_size_50_label').style.scale = '1.03';
        }
        imgPizza.forEach(function (pizza) {
            pizza.style.height = sizeValue;
        });
    }
}

/* Sauce */

document.querySelectorAll('.sauce_select').forEach(function (radio_sauce) {
    radio_sauce.addEventListener('click', checkSauce);
});

function checkSauce() {
    document.getElementById('radio_tomato_sauce_label').style.border = '';
    document.getElementById('radio_tomato_sauce_label').style.scale = '';

    document.getElementById('radio_pesto_sauce_label').style.border = '';
    document.getElementById('radio_pesto_sauce_label').style.scale = '';

    document.getElementById('radio_garlic_sauce_label').style.border = '';
    document.getElementById('radio_garlic_sauce_label').style.scale = '';

    document.getElementById('radio_no_sauce_label').style.border = '';
    document.getElementById('radio_no_sauce_label').style.scale = '';

    document.querySelectorAll('.sauce_pics').forEach(function (fade) {
        fade.style.opacity = 0;
    });
    if (document.getElementById('radio_tomato_sauce').checked) {
        document.getElementById('tomato_sauce').style.opacity = 1;
        document.getElementById('radio_tomato_sauce_label').style.border = '2px solid rgb(52, 202, 15)';
        document.getElementById('radio_tomato_sauce_label').style.scale = '1.03';
    }
    if (document.getElementById('radio_pesto_sauce').checked) {
        document.getElementById('pesto_sauce').style.opacity = 1;
        document.getElementById('radio_pesto_sauce_label').style.border = '2px solid rgb(52, 202, 15)';
        document.getElementById('radio_pesto_sauce_label').style.scale = '1.03';
    }
    if (document.getElementById('radio_garlic_sauce').checked) {
        document.getElementById('garlic_sauce').style.opacity = 1;
        document.getElementById('radio_garlic_sauce_label').style.border = '2px solid rgb(52, 202, 15)';
        document.getElementById('radio_garlic_sauce_label').style.scale = '1.03';
    }
    if (document.getElementById('radio_no_sauce').checked) {
        document.getElementById('radio_no_sauce_label').style.border = '2px solid rgb(52, 202, 15)';
        document.getElementById('radio_no_sauce_label').style.scale = '1.03';
    }
}

/* Toppings */

function checkCheese() {
    if (document.getElementById('check_cheese').checked == true) {
        document.getElementById('cheese').style.opacity = 1;
        document.getElementById('cheese_btn_div').style.outline = '2px solid rgb(52, 202, 15)';
        document.getElementById('cheese_btn_div').style.scale = '1.03';
    } else {
        document.getElementById('cheese').style.opacity = 0;
        document.getElementById('cheese_btn_div').style.outline = '';
        document.getElementById('cheese_btn_div').style.scale = '';
    }
}

function checkCorn() {
    if (document.getElementById('check_corn').checked == true) {
        document.getElementById('corn').style.opacity = 1;
        document.getElementById('corn_btn_div').style.outline = '2px solid rgb(52, 202, 15)';
        document.getElementById('corn_btn_div').style.scale = '1.03';
    } else {
        document.getElementById('corn').style.opacity = 0;
        document.getElementById('corn_btn_div').style.outline = '';
        document.getElementById('corn_btn_div').style.scale = '';
    }
}

function checkPepperoni() {
    if (document.getElementById('check_pepperoni').checked == true) {
        document.getElementById('pepperoni').style.opacity = 1;
        document.getElementById('pepperoni_btn_div').style.outline = '2px solid rgb(52, 202, 15)';
        document.getElementById('pepperoni_btn_div').style.scale = '1.03';
    } else {
        document.getElementById('pepperoni').style.opacity = 0;
        document.getElementById('pepperoni_btn_div').style.outline = '';
        document.getElementById('pepperoni_btn_div').style.scale = '';
    }
}

function checkMushrooms() {
    if (document.getElementById('check_mushrooms').checked == true) {
        document.getElementById('mushrooms').style.opacity = 1;
        document.getElementById('mushrooms_btn_div').style.outline = '2px solid rgb(52, 202, 15)';
        document.getElementById('mushrooms_btn_div').style.scale = '1.03';
    } else {
        document.getElementById('mushrooms').style.opacity = 0;
        document.getElementById('mushrooms_btn_div').style.outline = '';
        document.getElementById('mushrooms_btn_div').style.scale = '';
    }
}

function checkOnions() {
    if (document.getElementById('check_onions').checked == true) {
        document.getElementById('onions').style.opacity = 1;
        document.getElementById('onions_btn_div').style.outline = '2px solid rgb(52, 202, 15)';
        document.getElementById('onions_btn_div').style.scale = '1.03';
    } else {
        document.getElementById('onions').style.opacity = 0;
        document.getElementById('onions_btn_div').style.outline = '';
        document.getElementById('onions_btn_div').style.scale = '';
    }
}

function checkPineapple() {
    if (document.getElementById('check_pineapple').checked == true) {
        document.getElementById('pineapple').style.opacity = 1;
        document.getElementById('pineapple_btn_div').style.outline = '2px solid rgb(52, 202, 15)';
        document.getElementById('pineapple_btn_div').style.scale = '1.03';
    } else {
        document.getElementById('pineapple').style.opacity = 0;
        document.getElementById('pineapple_btn_div').style.outline = '';
        document.getElementById('pineapple_btn_div').style.scale = '';
    }
}

function checkHam() {
    if (document.getElementById('check_ham').checked == true) {
        document.getElementById('ham').style.opacity = 1;
        document.getElementById('ham_btn_div').style.outline = '2px solid rgb(52, 202, 15)';
        document.getElementById('ham_btn_div').style.scale = '1.03';
    } else {
        document.getElementById('ham').style.opacity = 0;
        document.getElementById('ham_btn_div').style.outline = '';
        document.getElementById('ham_btn_div').style.scale = '';
    }
}

function checkSpinach() {
    if (document.getElementById('check_spinach').checked == true) {
        document.getElementById('spinach').style.opacity = 1;
        document.getElementById('spinach_btn_div').style.outline = '2px solid rgb(52, 202, 15)';
        document.getElementById('spinach_btn_div').style.scale = '1.03';
    } else {
        document.getElementById('spinach').style.opacity = 0;
        document.getElementById('spinach_btn_div').style.outline = '';
        document.getElementById('spinach_btn_div').style.scale = '';
    }
}

function checkTomato() {
    if (document.getElementById('check_tomato').checked == true) {
        document.getElementById('tomato').style.opacity = 1;
        document.getElementById('tomato_btn_div').style.outline = '2px solid rgb(52, 202, 15)';
        document.getElementById('tomato_btn_div').style.scale = '1.03';
    } else {
        document.getElementById('tomato').style.opacity = 0;
        document.getElementById('tomato_btn_div').style.outline = '';
        document.getElementById('tomato_btn_div').style.scale = '';
    }
}

function checkTuna() {
    if (document.getElementById('check_tuna').checked == true) {
        document.getElementById('tuna').style.opacity = 1;
        document.getElementById('tuna_btn_div').style.outline = '2px solid rgb(52, 202, 15)';
        document.getElementById('tuna_btn_div').style.scale = '1.03';
    } else {
        document.getElementById('tuna').style.opacity = 0;
        document.getElementById('tuna_btn_div').style.outline = '';
        document.getElementById('tuna_btn_div').style.scale = '';
    }
}

function checkBroccoli() {
    if (document.getElementById('check_broccoli').checked == true) {
        document.getElementById('broccoli').style.opacity = 1;
        document.getElementById('broccoli_btn_div').style.outline = '2px solid rgb(52, 202, 15)';
        document.getElementById('broccoli_btn_div').style.scale = '1.03';
    } else {
        document.getElementById('broccoli').style.opacity = 0;
        document.getElementById('broccoli_btn_div').style.outline = '';
        document.getElementById('broccoli_btn_div').style.scale = '';
    }
}

function checkOlives() {
    if (document.getElementById('check_olives').checked == true) {
        document.getElementById('olives').style.opacity = 1;
        document.getElementById('olives_btn_div').style.outline = '2px solid rgb(52, 202, 15)';
        document.getElementById('olives_btn_div').style.scale = '1.03';
    } else {
        document.getElementById('olives').style.opacity = 0;
        document.getElementById('olives_btn_div').style.outline = '';
        document.getElementById('olives_btn_div').style.scale = '';
    }
}