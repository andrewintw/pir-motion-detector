# pir-motion-detector

HC-SR501 PIR Motion Detector


## Console output format

	{timestamp} pv:{PIR value} dc:{detected count} ndc:{no-detected count} Max(ndc):{max of ndc} {time(sec)}


## (v1) MotionDetect_Count

	...
	00:25:12 pv:0 dc:0	ndc:7	Max(ndc):42	42sec
	00:25:13 pv:0 dc:0	ndc:8	Max(ndc):42	42sec
	00:25:14 pv:0 dc:0	ndc:9	Max(ndc):42	42sec
	00:25:15 pv:0 dc:0	ndc:10	Max(ndc):42	42sec
	00:25:16 pv:0 dc:0	ndc:11	Max(ndc):42	42sec
	00:25:17 pv:1 dc:1	ndc:0	Max(ndc):42	42sec
	00:25:18 pv:1 dc:2	ndc:0	Max(ndc):42	42sec
	00:25:19 pv:1 dc:3	ndc:0	Max(ndc):42	42sec
	00:25:20 pv:0 dc:0	ndc:1	Max(ndc):42	42sec
	00:25:21 pv:0 dc:0	ndc:2	Max(ndc):42	42sec
	00:25:22 pv:0 dc:0	ndc:3	Max(ndc):42	42sec
	00:25:23 pv:0 dc:0	ndc:4	Max(ndc):42	42sec
	00:25:24 pv:1 dc:1	ndc:0	Max(ndc):42	42sec
	00:25:25 pv:1 dc:2	ndc:0	Max(ndc):42	42sec
	00:25:26 pv:1 dc:3	ndc:0	Max(ndc):42	42sec
	00:25:27 pv:0 dc:0	ndc:1	Max(ndc):42	42sec
	00:25:28 pv:0 dc:0	ndc:2	Max(ndc):42	42sec
	00:25:29 pv:0 dc:0	ndc:3	Max(ndc):42	42sec
	00:25:30 pv:0 dc:0	ndc:4	Max(ndc):42	42sec
	00:25:31 pv:1 dc:1	ndc:0	Max(ndc):42	42sec
	00:25:32 pv:1 dc:2	ndc:0	Max(ndc):42	42sec
	00:25:33 pv:0 dc:0	ndc:1	Max(ndc):42	42sec
	00:25:34 pv:0 dc:0	ndc:2	Max(ndc):42	42sec
	00:25:35 pv:0 dc:0	ndc:3	Max(ndc):42	42sec
	00:25:36 pv:0 dc:0	ndc:4	Max(ndc):42	42sec
	00:25:37 pv:0 dc:0	ndc:5	Max(ndc):42	42sec


## (v2) MotionDetect_Period

	...
	00:17:39  pv:1 dc:2	ndc:0	Max(ndc):27  27sec   | 20
	00:17:40  pv:1 dc:3	ndc:0	Max(ndc):27  27sec   | 21
	00:17:41  pv:1 dc:4	ndc:0	Max(ndc):27  27sec   | 22
	00:17:42  pv:1 dc:5	ndc:0	Max(ndc):27  27sec   | 23
	00:17:43  pv:0 dc:0	ndc:1	Max(ndc):27  27sec __x 23
	00:17:44  pv:0 dc:0	ndc:2	Max(ndc):27  27sec
	00:17:45  pv:0 dc:0	ndc:3	Max(ndc):27  27sec
	00:17:46  pv:0 dc:0	ndc:4	Max(ndc):27  27sec
	00:17:47  pv:0 dc:0	ndc:5	Max(ndc):27  27sec
	00:17:48  pv:1 dc:1	ndc:0	Max(ndc):27  27sec --* (60sec)
	00:17:49  pv:1 dc:2	ndc:0	Max(ndc):27  27sec   | 1
	00:17:50  pv:1 dc:3	ndc:0	Max(ndc):27  27sec   | 2
	00:17:51  pv:1 dc:4	ndc:0	Max(ndc):27  27sec   | 3
	00:17:52  pv:1 dc:5	ndc:0	Max(ndc):27  27sec   | 4
	00:17:53  pv:1 dc:6	ndc:0	Max(ndc):27  27sec   | 5
	00:17:54  pv:1 dc:7	ndc:0	Max(ndc):27  27sec   | 6
	...
	00:18:23  pv:0 dc:0	ndc:2	Max(ndc):27  27sec   | 10
	00:18:24  pv:0 dc:0	ndc:3	Max(ndc):27  27sec   | 10
	00:18:25  pv:0 dc:0	ndc:4	Max(ndc):27  27sec   | 10
	00:18:26  pv:0 dc:0	ndc:5	Max(ndc):27  27sec   | 10
	00:18:27  pv:1 dc:1	ndc:0	Max(ndc):27  27sec   | 11
	00:18:28  pv:0 dc:0	ndc:1	Max(ndc):27  27sec   | 11
	...
	00:18:45  pv:1 dc:1	ndc:0	Max(ndc):27  27sec   | 16
	00:18:46  pv:0 dc:0	ndc:1	Max(ndc):27  27sec   | 16
	00:18:47  pv:0 dc:0	ndc:2	Max(ndc):27  27sec   | 16
	00:18:48  pv:0 dc:0	ndc:3	Max(ndc):27  27sec __x 16
	00:18:49  pv:0 dc:0	ndc:4	Max(ndc):27  27sec
	00:18:50  pv:0 dc:0	ndc:5	Max(ndc):27  27sec
	00:18:51  pv:0 dc:0	ndc:6	Max(ndc):27  27sec
	00:18:52  pv:0 dc:0	ndc:7	Max(ndc):27  27sec
	00:18:53  pv:0 dc:0	ndc:8	Max(ndc):27  27sec
	00:18:54  pv:1 dc:1	ndc:0	Max(ndc):27  27sec --* (60sec)
	00:18:55  pv:0 dc:0	ndc:1	Max(ndc):27  27sec   | 0
	00:18:56  pv:0 dc:0	ndc:2	Max(ndc):27  27sec   | 0
	00:18:57  pv:0 dc:0	ndc:3	Max(ndc):27  27sec   | 0
	...
	00:19:17  pv:0 dc:0	ndc:23	Max(ndc):27  27sec   | 0
	00:19:18  pv:0 dc:0	ndc:24	Max(ndc):27  27sec   | 0
	00:19:19  pv:0 dc:0	ndc:25	Max(ndc):27  27sec   | 0
	00:19:20  pv:0 dc:0	ndc:26	Max(ndc):27  27sec   | 0
	00:19:21  pv:1 dc:1	ndc:0	Max(ndc):27  27sec   | 1
	00:19:22  pv:0 dc:0	ndc:1	Max(ndc):27  27sec   | 1
	00:19:23  pv:0 dc:0	ndc:2	Max(ndc):27  27sec   | 1
	00:19:24  pv:0 dc:0	ndc:3	Max(ndc):27  27sec   | 1
	00:19:25  pv:0 dc:0	ndc:4	Max(ndc):27  27sec   | 1
	00:19:26  pv:0 dc:0	ndc:5	Max(ndc):27  27sec   | 1
	00:19:27  pv:0 dc:0	ndc:6	Max(ndc):27  27sec   | 1
	00:19:28  pv:0 dc:0	ndc:7	Max(ndc):27  27sec   | 1
	00:19:29  pv:0 dc:0	ndc:8	Max(ndc):27  27sec   | 1
	00:19:30  pv:1 dc:1	ndc:0	Max(ndc):27  27sec   | 2
	00:19:31  pv:1 dc:2	ndc:0	Max(ndc):27  27sec   | 3
	00:19:32  pv:0 dc:0	ndc:1	Max(ndc):27  27sec   | 3
	00:19:33  pv:0 dc:0	ndc:2	Max(ndc):27  27sec   | 3
	...
	00:19:51  pv:0 dc:0	ndc:20	Max(ndc):27  27sec   | 3
	00:19:52  pv:0 dc:0	ndc:21	Max(ndc):27  27sec   | 3
	00:19:53  pv:0 dc:0	ndc:22	Max(ndc):27  27sec   | 3
	00:19:54  pv:0 dc:0	ndc:23	Max(ndc):27  27sec __x 3
	00:19:55  pv:0 dc:0	ndc:24	Max(ndc):27  27sec
	00:19:56  pv:0 dc:0	ndc:25	Max(ndc):27  27sec
	...

## LICENSE

	/*
	 * --------------------------------------------------------------------------------
	 * "THE BEER-WARE LICENSE" (Revision 42):
	 * <yenchang.lin@gmail.com>  wrote this program.  As long as you retain this notice
	 * you can do whatever you want with this stuff. If we meet some day, and you think
	 * this stuff is worth it, you can buy me a beer in return.  Andrew Lin
	 * --------------------------------------------------------------------------------
	 */
