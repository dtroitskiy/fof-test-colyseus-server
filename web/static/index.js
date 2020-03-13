document.addEventListener('DOMContentLoaded', function()
{
	const latencyElem = document.querySelector('#latency');
	
	function updateLatency()
	{
		var time = Date.now();
		var req = new XMLHttpRequest();
		req.addEventListener('readystatechange', function()
		{
			if (req.readyState === XMLHttpRequest.DONE)
			{
				latencyElem.innerText = Math.round((Date.now() - time) / 2) + ' ms';
				setTimeout(requestAnimationFrame.bind(window, updateLatency), 1000);
			}
		});
		req.open('GET', '/api/ping');
		req.send();
	}

	requestAnimationFrame(updateLatency);

	const playersElem = document.querySelector('#players');
	const roomsElem = document.querySelector('#rooms');

	function updatePlayersAndRooms()
	{
		var req = new XMLHttpRequest();
		req.addEventListener('readystatechange', function()
		{
			if (req.readyState === XMLHttpRequest.DONE)
			{
				const data = JSON.parse(req.response);
				playersElem.innerText = data.connections;
				roomsElem.innerText = data.rooms.length;
				setTimeout(requestAnimationFrame.bind(window, updatePlayersAndRooms), 5000);
			}
		});
		req.open('GET', '/colyseus/api');
		req.send();
	}

	requestAnimationFrame(updatePlayersAndRooms);

});
