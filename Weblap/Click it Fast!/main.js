let counter = 0;

function pickRandomNumberInRange() {
    let randomNumber;
    let squares = document.querySelectorAll('.square');

    squares.forEach(square => {
        square.style.background = 'none';
        square.removeEventListener('click', handleClick);
        square.addEventListener('click', handleClick);
    });

    if (!randomNumber) {
        randomNumber = Math.floor(Math.random() * 40) + 1;
        document.getElementById(randomNumber).style.backgroundColor = "red";
    }

    function handleClick(event) {
        if (event.target.id == randomNumber) {
            counter++;
            document.querySelector('.points').textContent = `${counter}`;
            squares.forEach(square => square.removeEventListener('click', handleClick));
        }
    }

    setTimeout(pickRandomNumberInRange, 1000);
}

pickRandomNumberInRange();
