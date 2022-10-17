import axios from "axios";

import logo from './logo.svg';
import './App.css';
import React from "react";


const baseURL = "https://testapi.io/api/marvo/cities";

function App() {

  const [cities, setCities] = React.useState([]);
  const [final, setFinal] = React.useState([]);


  React.useEffect(() => {
    axios.get(baseURL).then(response => {
      let finalCities = [];
      console.log("Hello")
      setCities(response.data);

      response.data.map(city => {
        axios.get(`http://api.positionstack.com/v1/reverse?access_key=1dd2ba62b9a981fd7b4fc1ebba392da5&query=${city.latitude},${city.longitude}`).then((response => {
          console.log("Second, hopefully");
          console.log(response.data);
          finalCities.push({
            "city":response.data.region,
            "latitude":city.latitude,
            "longitude":city.longitude,
          });
        }))
      })

      setFinal(finalCities);
      
    })
  })

  return (
    <div className="App">
      <header className="App-header">
        <h1>WaterFlow Monitor</h1>
        {/* <p>{cities[0].name}</p> */}
      </header>
    </div>
  );
}

export default App;
