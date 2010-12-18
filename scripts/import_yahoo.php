<?php

/* In order to use this you need to name the file csv file downloaded from yahoo 
//to <symbol_name>.csv and to execute this script just run
// php -f ./import_yahoo.php -- <symbol>.csv
// 
//Its important that you run it exactly like this. 
*/


$SERVER="127.0.0.1";
$USER="root";
$PASS="thelinux";
$DATABASE="traitor";

/**
 * Generate a random UUID
 *
 * @see http://www.ietf.org/rfc/rfc4122.txt
 * @return RFC 4122 UUID
 * @static
 */
	function uuid() {
		$node = "127.0.0.1";
		$pid = null;

		if (strpos($node, ':') !== false) {
			if (substr_count($node, '::')) {
				$node = str_replace(
					'::', str_repeat(':0000', 8 - substr_count($node, ':')) . ':', $node
				);
			}
			$node = explode(':', $node) ;
			$ipv6 = '' ;

			foreach ($node as $id) {
				$ipv6 .= str_pad(base_convert($id, 16, 2), 16, 0, STR_PAD_LEFT);
			}
			$node =  base_convert($ipv6, 2, 10);

			if (strlen($node) < 38) {
				$node = null;
			} else {
				$node = crc32($node);
			}
		} elseif (empty($node)) {
			$host = env('HOSTNAME');

			if (empty($host)) {
				$host = env('HOST');
			}

			if (!empty($host)) {
				$ip = gethostbyname($host);

				if ($ip === $host) {
					$node = crc32($host);
				} else {
					$node = ip2long($ip);
				}
			}
		} elseif ($node !== '127.0.0.1') {
			$node = ip2long($node);
		} else {
			$node = null;
		}

		if (empty($node)) {
			$node = crc32('lfjloishdfh4lj34523o84i5uoquhbrgalfh');
		}

		if (function_exists('zend_thread_id')) {
			$pid = zend_thread_id();
		} else {
			$pid = getmypid();
		}

		if (!$pid || $pid > 65535) {
			$pid = mt_rand(0, 0xfff) | 0x4000;
		}

		list($timeMid, $timeLow) = explode(' ', microtime());
		$uuid = sprintf(
			"%08x-%04x-%04x-%02x%02x-%04x%08x", (int)$timeLow, (int)substr($timeMid, 2) & 0xffff,
			mt_rand(0, 0xfff) | 0x4000, mt_rand(0, 0x3f) | 0x80, mt_rand(0, 0xff), $pid, $node
		);

		return $uuid;
	}


	$db = mysql_connect($SERVER,$USER,$PASS) or die("Unable to connect to mysql database: " . mysql_error());
	mysql_select_db($DATABASE,$db) or die("Unable able to select database: " . mysql_error());


	$file = file($argv[1]);
	$file_name = explode(".",$argv[1]);
	$symbol = $file_name[0];

	for($i = 1; $i < count($file); $i++)
	{
		$splode = explode(",",$file[$i]);
		print_r($splode);
		$sql = "INSERT INTO `traitor`.`quotes` (`uuid`, `date`, `open`, `high`, `low`, `close`, `volume`, `adj_close`,`symbol`) VALUES ('" . uuid(). "', '".$splode[0]."', '".$splode[1]."', '".$splode[2]."', '".$splode[3]."', '".$splode[4]."', '".$splode[5]."', '".$splode[6]."','".$symbol."');";
		echo $sql;	
		mysql_query($sql) or die('Error inserting into database: ' . mysql_error());
	}
		




 

?>
