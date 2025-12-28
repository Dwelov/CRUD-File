
<body>
  <h1>CSV CRUD Project</h1>

  <h2>Description</h2>
  <p>
    A C++ program that demonstrates Create, Read, Update, and Delete operations on a CSV file.
    It is designed for learning file handling, data validation, and CRUD logic in a practical way.
  </p>

  <h2>Features</h2>
  <ul>
    <li><strong>Create Records</strong> – Add new entries into the CSV file with proper formatting.</li>
    <li><strong>Read the File</strong> – Display all stored records in a clear, structured format.</li>
    <li><strong>Update Records</strong> – Modify existing data entries without breaking file integrity.</li>
    <li><strong>Delete Records</strong> – Remove unwanted or outdated records safely from the file.</li>
    <li><strong>Validate Roll Numbers</strong> – Ensure that each student’s roll number is unique and valid.</li>
    <li><strong>Add Students</strong> – Append new student information into the file seamlessly.</li>
    <li><strong>Search Data</strong> – Quickly locate specific records using keywords or roll numbers.</li>
    <li><strong>Exit Program</strong> – Close the application gracefully when finished.</li>
  </ul>

  <h2>Installation</h2>
  <ol>
    <li>
      Clone the repository:
      <pre><code>git clone https://github.com/Dwelov/CRUD-File</code></pre>
    </li>
    <li>
      Compile the program:
      <pre><code>g++ main.cpp search.cpp validation.cpp crud.cpp -o main.exe</code></pre>
    </li>
  </ol>

  <h2>Usage</h2>
  <p>Run the program:</p>
  <pre><code>./main.exe</code></pre>
  <p>
    Follow the on-screen menu to perform CRUD operations, validate roll numbers, add students, or search data.
  </p>
</body>

