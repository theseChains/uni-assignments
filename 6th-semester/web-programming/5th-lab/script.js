const graphContainer = document.getElementById('graphContainer');
const gridWidth = 800;
const gridHeight = 800;

graphContainer.style.width = gridWidth + 'px';
graphContainer.style.height = gridHeight + 'px';

let scale = 1;
let gridSize = 50;

const moveX =
    parseFloat(new URLSearchParams(window.location.search).get('dx')) || 0;
const moveY =
    parseFloat(new URLSearchParams(window.location.search).get('dy')) || 0;

function plotGraph() {
    let x = -5;
    while (x <= 5) {
        const y = gridHeight / 2 - 2 * x * Math.sin(1 - x * x) * gridSize;
        const point = document.createElement('div');
        point.className = 'graphPoint';
        point.style.top = y + 'px';
        point.style.left = (gridWidth / 2 + x * 2 * gridSize) + 'px';
        graphContainer.appendChild(point);
        x += 0.01;
    }

    const graphPoints = document.getElementsByClassName('graphPoint');
    for (const point of graphPoints) {
        const currentTop = parseInt(point.style.top, 10);
        const currentLeft = parseInt(point.style.left, 10);

        const newTop = currentTop + moveY;
        const newLeft = currentLeft + moveX;
        point.style.top = newTop + 'px';
        point.style.left = newLeft + 'px';
    }
}

function scaleGraphUp() {
    scale += 0.5;
    updateGraph();
}

function scaleGraphDown() {
    scale -= 0.5;
    if (scale <= 0) {
        scale = 0.5;
        return;
    }
    updateGraph();
}

function updateGraph() {
    gridSize = 50 * scale;
    removeAllGraphPoints();
    plotGraph();
}

function removeAllGraphPoints() {
    const graphPoints = document.querySelectorAll('.graphPoint');
    graphPoints.forEach(point => point.remove());
}

document.getElementById('scaleUpButton').addEventListener("click", scaleGraphUp);
document.getElementById('scaleDownButton').addEventListener("click", scaleGraphDown);

function drawGrid() {
    for (let i = 0; i < gridWidth; i += gridSize) {
        const horizontalLine = document.createElement('div');
        horizontalLine.className = 'gridLine';
        horizontalLine.style.width = '100%';
        horizontalLine.style.height = '2px';
        horizontalLine.style.top = i + 'px';
        graphContainer.appendChild(horizontalLine);

        const verticalLine = document.createElement('div');
        verticalLine.className = 'gridLine';
        verticalLine.style.width = '2px';
        verticalLine.style.height = '100%';
        verticalLine.style.left = i + 'px';
        graphContainer.appendChild(verticalLine);

        if (i == gridWidth / 2){
            horizontalLine.style.background = 'green';
            verticalLine.style.background = 'green';
        }
    }
}

plotGraph();
drawGrid();
