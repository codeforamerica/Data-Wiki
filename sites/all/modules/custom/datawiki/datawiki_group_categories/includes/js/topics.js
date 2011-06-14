var cityGroups = {};
cityGroups.topics = {};

cityGroups.topics.paths = {
  // TODO add view that spits out taxonomy term data.
    "defaultPath": "group_categories_data",
};
     
$(document).ready(function() {
  cityGroups.loadData(cityGroups.topics.paths['defaultPath']);
  cityGroups.topicPageInteractions();
});


cityGroups.topicPageInteractions = function () {

};


cityGroups.loadData = function(path) {
/*   var dataPath = "http://localhost/codeforamerica/citygroups/citygroups_map/data/community-groups-data.json"; */
if (path === undefined) {
  var path = "community-groups-data";
}
/*   var dataPath = "sites/all/modules/custom/datawiki/datawiki_group_map/includes/data/community-groups-data.json"; */
  var data = "";

  $.ajax({
    url: path,
    dataType: 'json',
    data: data,
    success: cityGroups.loadDataSuccess,
    error: cityGroups.loadDataError
  });

  return false;
};

cityGroups.loadDataError = function(data) {
  console.log("error");
  return false;
};

cityGroups.loadDataSuccess = function(data) {
  console.log("success!");
  cityGroups.data = data;
  cityGroups.map.loadMap();
  cityGroups.geoJSON(cityGroups.data.nodes);
  return false;
};


