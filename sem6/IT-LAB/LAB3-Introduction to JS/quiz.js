var quiz = document.getElementById("quiz");

var questions = [
  {
    question: "When did India get Independence?",
    options: ["1948", "1947", "1946", "1951"],
    answer: "1947",
  },
  {
    question: "Who was the first President of India?",
    options: [
      "Rajendra Prasad",
      "Gandhi Ji",
      "Jawaharlal Nehru",
      "Dr. Sarvepalli Radhakrishnan",
    ],
    answer: "Rajendra Prasad",
  },
  {
    question: "What is the capital of India?",
    options: ["Delhi", "Punjab", "Mumbai", "NCR"],
    answer: "Delhi",
  },
  {
    question: "What is the financial capital of India?",
    options: ["Delhi", "Punjab", "Mumbai", "NCR"],
    answer: "Mumbai",
  },
];

questions.map((question, index) => {
    var child = document.createElement("div");
    child.setAttribute("id", `${index}`);
    child.innerHTML = `<p>${question.question}</p>`;
    var form = document.createElement("form");

    question.options.map((option, optionIndex) =>{
        var input = document.createElement("input");
        input.type = "radio";
        input.name = `option${index}`;
        input.value = option;
        input.id = `option${index}_${optionIndex}`;
        var label = document.createElement("label");
        label.htmlFor = `option${index}_${optionIndex}`;
        label.textContent = option;

        form.appendChild(input);
        form.appendChild(label);
        form.appendChild(document.createElement("br"));
    });

    var submitButton = document.createElement("button");
    submitButton.type = "button";
    submitButton.textContent = "Submit";
    submitButton.onclick = function() {
        checkAnswer(index);
    };

    form.appendChild(submitButton);
    child.appendChild(form);
    quiz.appendChild(child);
});

function checkAnswer(questionIndex) {
    var selectedOption = document.querySelector(`input[name="option${questionIndex}"]:checked`);
    if (selectedOption) {
        var userAnswer = selectedOption.value;
        var correctAnswer = questions[questionIndex].answer;

        if (userAnswer === correctAnswer) {
            alert("Correct!");
        } else {
            alert(`Incorrect. The correct answer is ${correctAnswer}.`);
        }
    } else {
        alert("Please select an answer before submitting.");
    }
}
