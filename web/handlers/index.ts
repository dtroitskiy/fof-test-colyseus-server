export class Index
{
	get(req, res)
	{
		var pjson = require('../../package.json');
		res.render('index', {
			'version': pjson.version,
			'pretty': true
		});
	}
}
