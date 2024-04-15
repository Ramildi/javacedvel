 function addRow() {
    var table = document.getElementById("myTable").getElementsByTagName('tbody')[0];
    var newRow = table.insertRow(table.rows.length);
    var cells = [];

    for (var i = 0; i < 5; i++) {
        cells[i] = newRow.insertCell(i);
        if (i < 3) {
            cells[i].innerHTML = '<input type="text" placeholder="' + ["Ad", "Soyad", "Yaş"][i] + '">';
        } else if (i === 3) {
            cells[i].innerHTML = '<button onclick="editRow(this)">Düzəliş Et</button>';
        } else {
            cells[i].innerHTML = '<button onclick="deleteRow(this)">Sil</button>';
        }
    }
}

function editRow(button) {
    var row = button.parentNode.parentNode;
    var cells = row.getElementsByTagName('td');
    for (var i = 0; i < cells.length - 2; i++) {
        var cellText = cells[i].innerText;
        cells[i].innerHTML = '<input type="text" value="' + cellText + '">';
    }
    var saveButton = document.createElement('button');
    saveButton.innerHTML = 'Yadda Saxla';
    saveButton.className = 'save-button';
    saveButton.onclick = function() {
        saveRow(this);
        this.style.backgroundColor = 'red';
    };
    cells[3].innerHTML = '';
    cells[3].appendChild(saveButton);
}

function saveRow(button) {
    var row = button.parentNode.parentNode;
    var cells = row.getElementsByTagName('td');
    for (var i = 0; i < cells.length - 2; i++) {
        var input = cells[i].querySelector('input');
        cells[i].innerText = input.value;
    }
    cells[3].innerHTML = '<button onclick="editRow(this)">Düzəliş Et</button>';
}

function deleteRow(button) {
    var row = button.parentNode.parentNode;
    row.parentNode.removeChild(row);
}