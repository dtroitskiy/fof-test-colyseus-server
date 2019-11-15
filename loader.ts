import { FS, ObjectsCollection, ProgressCallback, DB, OTBMap, UniversalTileMap, CombatSystem } from './FoFcombat/FoFcombat';
import * as FoFcombat from './FoFcombat/FoFcombat';

export class Loader
{
	static isInited: boolean = false;

	static init()
	{
		if (this.isInited) return;
		FS.mkdir('/res');
		FS.mount(FS.filesystems.NODEFS, { root: '../../FoFdata/res' }, '/res');
		this.isInited  = true;
	}

	static loadDB()
	{
		const db = DB.getInstance();
		db.open('/res/data.db');
		return db;
	}

	static loadResources()
	{
		const oc = ObjectsCollection.getInstance();
		
		let progressCallback = new ProgressCallback(function(progress)
		{
			const percentage = Math.round(progress * 100);
			if (percentage != progressCallback.lastPercentage)
			{
				console.log('Loading %s - %i\%', file, percentage);
				progressCallback.lastPercentage = percentage;
			}
		});
		
		// dat
		let file = 'fof.dat';
		oc.loadData('/res/' + file, progressCallback);
		
		// spr
		file = 'fof.spr';
		oc.loadSpritesRGB('/res/' + file, progressCallback, false);
		
		// alp
		file = 'fof.alp';
		oc.loadSpritesAlpha('/res/' + file, progressCallback, false);
		
		// blk
		file = 'fof.blk';
		oc.loadSpritesBlockingStatesAndElevations('/res/' + file, progressCallback);
		
		// aoa
		file = 'fof.aoa';
		oc.loadAdvancedObjectAttributes('/res/' + file, progressCallback);
	}

	static loadMap(mapFilename)
	{
		if (!mapFilename) mapFilename = 'test.otbm';
		
		let progressCallback = new ProgressCallback(function(progress)
		{
			const percentage = Math.round(progress * 100);
			if (percentage != progressCallback.lastPercentage)
			{
				console.log('Loading %s - %i\%', mapFilename, percentage);
				progressCallback.lastPercentage = percentage;
			}
		});
		
		const otbMap = new OTBMap();
		otbMap.load('/res/maps/' + mapFilename, progressCallback);

		progressCallback = new ProgressCallback(function(progress)
		{
			const percentage = Math.round(progress * 100);
			if (percentage != progressCallback.lastPercentage)
			{
				console.log('Building map - %i\%', percentage);
				progressCallback.lastPercentage = percentage;
			}
		});
		
		const universalTileMap = new UniversalTileMap();
		universalTileMap.build(otbMap, progressCallback);

		return universalTileMap;
	}
}
