# Two-Pointer Algorithms - Frontend

A modern, interactive web interface for the Two-Pointer Algorithms library.

## Features

- **Beautiful UI**: Modern gradient design with smooth animations
- **Interactive**: Real-time algorithm demonstrations
- **Responsive**: Works on desktop and mobile devices
- **User-Friendly**: Clear input fields and instant feedback
- **Educational**: Shows time and space complexity for each algorithm

## Algorithms Included

1. **Reverse String** - Reverse any string in place
2. **Palindrome Checker** - Check if a string is a palindrome
3. **Remove Duplicates** - Remove duplicates from a sorted array
4. **Merge Sorted Arrays** - Merge two sorted arrays into one

## How to Use

Simply open `index.html` in any modern web browser:

```bash
# Option 1: Double-click index.html
# Option 2: Open in browser
open index.html  # macOS
xdg-open index.html  # Linux
start index.html  # Windows

# Option 3: Use a local server (recommended for development)
python -m http.server 8000
# Then visit http://localhost:8000
```

## Using the Interface

1. **Reverse String**: Enter any string and click "Reverse String"
2. **Palindrome Checker**: Enter a string and click "Check Palindrome"
3. **Remove Duplicates**: Enter a sorted array (comma-separated) and click "Remove Duplicates"
4. **Merge Sorted Arrays**: Enter two sorted arrays (comma-separated) and click "Merge Arrays"

## Technical Details

- **Pure HTML/CSS/JavaScript**: No dependencies required
- **Responsive Design**: Uses CSS Grid and Flexbox
- **Modern ES6+ JavaScript**: Clean, readable code
- **Algorithm Implementations**: JavaScript versions of the C++ backend algorithms

## Browser Compatibility

- Chrome/Edge (recommended)
- Firefox
- Safari
- Opera

## Integration with Backend

The frontend currently implements the algorithms in JavaScript for demonstration purposes. To integrate with the C++ backend:

1. Create a REST API server using the C++ backend
2. Update the JavaScript to make HTTP requests to the API
3. Display the results from the backend

## Future Enhancements

- [ ] Direct integration with C++ backend via REST API
- [ ] Add more visualization options
- [ ] Include step-by-step algorithm animation
- [ ] Add performance comparison charts
- [ ] Support for more data types
