#!/usr/bin/node
const id = process.argv.slice(2);
const url = `https://swapi-api.hbtn.io/api/films/${id[0]}/`;

const request = require('request');
request(url, function (error, response, body) {
  const bodyJson = JSON.parse(body);
  for (const characters of bodyJson.characters) {
    request(characters, function (error, response, body) {
      const bdJson = JSON.parse(body);
      console.log(bdJson.name);
    });
  }
});
