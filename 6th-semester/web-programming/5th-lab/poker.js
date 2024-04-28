let numberOfCards = 0;
let cardImages = [];

function addCard() {
    if (numberOfCards < 5) {
        const cardValue = document.getElementById('cardValue').value;
        const cardSuit = document.getElementById('cardSuit').value;
        displaySelectedCardImage(cardValue, cardSuit);
        ++numberOfCards;
    }
}

function displaySelectedCardImage(cardValue, cardSuit) {
    const imagePath = `cards/${cardValue}${cardSuit}.png`;

    const cardImage = document.createElement('img');
    cardImage.src = imagePath;
    cardImage.alt = `${cardValue} of ${cardSuit}`;

    const selectedCardImagesContainer = document.getElementById('selectedCardImages');
    selectedCardImagesContainer.appendChild(cardImage);

    cardImages.push(cardImage);
}

document.getElementById('addCardButton').addEventListener('click', addCard);

function removeCard() {
    if (numberOfCards == 0) return;
    removeCardExecutor(numberOfCards - 1);
}

function removeCardExecutor(index) {
    const selectedCardImagesContainer = document.getElementById('selectedCardImages');
    selectedCardImagesContainer.removeChild(selectedCardImagesContainer.firstChild);

    cardImages.splice(index, 1);
    --numberOfCards;
}

document.getElementById('removeLastCard').addEventListener('click', removeCard);

function clearHand() {
    numberOfCards = 0;
    const cardImagesContainer = document.getElementById('selectedCardImages');
    while (cardImagesContainer.firstChild) {
        cardImagesContainer.removeChild(cardImagesContainer.firstChild);
    }
}

document.getElementById('clearCardsButton').addEventListener('click', clearHand);

function checkForFullHouse() {
    const rankCounts = {};

    for (const cardImage of cardImages) {
        const rank = cardImage.alt.split(' ')[0];
        rankCounts[rank] = (rankCounts[rank] || 0) + 1;
    }

    let hasTwoOfSameRank = false;
    let hasThreeOfSameRank = false;
    for (const rank in rankCounts) {
        if (rankCounts[rank] === 2) {
            hasTwoOfSameRank = true;
        } else if (rankCounts[rank] === 3) {
            hasThreeOfSameRank = true;
        }
    }

    const answerDiv = document.getElementById('answer');
    if (hasTwoOfSameRank && hasThreeOfSameRank) {
        answerDiv.textContent = "Есть фулл хаус";
    } else {
        answerDiv.textContent = "Нет фулл хауса";
        throw new Error("Нет игры");
    }
}

document.getElementById('fullHouseCheck').addEventListener('click', checkForFullHouse);
