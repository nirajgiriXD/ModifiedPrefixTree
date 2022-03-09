# beatingBinarySearch

The program is written in python and JSON file is used to store the data structure and the algorithm is still in progress for achieving its goal.

The data structure I have used here is tree but instead of saving the words in nodes I have broken down each word into characters.
Each character is saved into a node in hierarchy. 
This new approach is theoritically independent of the size of array from where the word is to be searched.
The time complexity is **_O(nlogm)_** where n is the size of word to be searched and m is the average number of nodes at a given level which can range between 0-256.
This searching algorithm is an approach to beating the binary search and is still in progress.

The basic structure is like this:
parent{
  anchor: charOfWord,
  basket: contentIfAny,
  child: childNode
}

For example: (cat, dog, don)

{
  "a": "c",
  "b": null,
  "c": {
      "a": "a",
      "b": null,
      "c": {
          "a": "t",
          "b": "Cat is blah blah blah",
          "c": null
      }
  },
  "a": "d",
  "b": null,
  "c": {
      "a": "o",
      "b": null,
      "c": {
          "a": "g",
          "b": "Dog is blah blah blah",
          "c": null
        },
        {
          "a": "n",
          "b": "Don is blah blah blah",
          "c": null
        }
    }
}

Any kind of suggestion for the improvement of algorithm or program will be highly appreciated.

XD
